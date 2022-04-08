// Player.cpp
// (c) 2018 FabLab Kannai
//
#include "Game1.h"

//===========================================
// Bullet
//-------------------------------------------
// Bullet::Bullet() {}
//-------------------------------------------
void Bullet::init(uint8_t val, unsigned long interval) {
  _val = val;
  _x = 0;
  _time = millis();
  _interval = interval;
  // print("init()");
}
//-------------------------------------------
uint8_t Bullet::val() {
  return _val;
}
//-------------------------------------------
uint8_t Bullet::x() {
  return _x;
}
//-------------------------------------------
unsigned long Bullet::time() {
  return _time;
}
//-------------------------------------------
unsigned long Bullet::interval() {
  return _interval;
}
//-------------------------------------------
boolean Bullet::move(unsigned long cur_msec) {
  if ( _val == VAL_NULL ) {
    return false;
  }
  if ( cur_msec - _time < _interval ) {
    return false;
  }

  print("move()");

  _time = cur_msec;
  _x++;
  if ( _x >= 6 ) {
    _val = VAL_NULL;
  }
  return true;
}
//-------------------------------------------
void Bullet::print(String prefix) const
{
  String str = "Bullet:" + prefix + ":_val=" + String(_val) + ", _x=" + String(_x, 10);
  Serial.println(str);
}  
//===========================================
// Player
//-------------------------------------------
Player::Player() {
  Player::init(0);
}
//-------------------------------------------
void Player::init(uint8_t val) {
  _val = val;
  _bullet.init(Bullet::VAL_NULL, 0);
}
//-------------------------------------------
uint8_t Player::val() {
  return _val;
}
//-------------------------------------------
Bullet *Player::bullet() {
  return &_bullet;
}
//-------------------------------------------
void Player::up() {
  _val = ( _val + 1 ) % 10;
}
//-------------------------------------------
void Player::down() {
  if ( _val == 0 ) {
    _val = 9;
  } else {
    _val--;
  }
}
//-------------------------------------------
void Player::shoot(unsigned long bullet_interval) {
  if ( _bullet.val() != Bullet::VAL_NULL ) {
    return;
  }
  Serial.println("shoot(" + String(bullet_interval) + ")");
  _bullet.init(_val, bullet_interval);
}
//-------------------------------------------
void Player::bullet_delete() {
  if ( _bullet.val() == Bullet::VAL_NULL ) {
    return;
  }
  _bullet.init(Bullet::VAL_NULL, 0);
}
//===========================================
// Enemy
//-------------------------------------------
Enemy::Enemy() {
  Enemy::init(0);
}
//-------------------------------------------
Enemy::Enemy(unsigned long interval) {
  Enemy::init(interval);
}
//-------------------------------------------
void Enemy::init(unsigned long interval) {
  _interval = interval;
  _time = 0;
  _size = 0;
}
//-------------------------------------------
uint8_t Enemy::val(size_t i) {
  return _val[i];
}
//-------------------------------------------
uint8_t Enemy::x() {
  return (6 - _size);
}
//-------------------------------------------
uint8_t Enemy::size() {
  return _size;
}
//-------------------------------------------
unsigned long Enemy::time() {
  return _time;
}
//-------------------------------------------
unsigned long Enemy::interval() {
  return _interval;
}
//-------------------------------------------
void Enemy::set_interval(unsigned long interval) {
  _interval = interval;
}
//-------------------------------------------
boolean Enemy::move(unsigned long cur_msec) {
  if ( cur_msec - _time < _interval ) {
    return false;
  }
  if ( _size >= 6 ) {
    return false;
  }

  _val[_size] = random(10);
  _size++;
  _time = cur_msec;
  return true;
}
//-------------------------------------------
void Enemy::hit() {
  if ( _size <= 0 ) {
    return;
  }
  
  _size--;
  for (int i=0; i < _size; i++) {
    _val[i] = _val[i+1];
  }
}
//-------------------------------------------
void Enemy::print(String prefix)
{
  String str = "Enemy:" + prefix + ":x=" + String(_x) + "val[]={ ";
  for (int i=0; i < _size; i++) {
    str += String(_val[i]) + " ";
  }
  str += "}";

  Serial.println(str);
}
//===========================================
// Game1
//-------------------------------------------
//Game1::Game1() {}
//-------------------------------------------
void Game1::init(VFD *vfd)
{
  _vfd = vfd;

  _p1.init(0);
  _e1.init(ENEMY_INTERVAL);

  _score = 0;
  set_mode(MODE_PLAY);
}
//-------------------------------------------
void Game1::loop(unsigned long cur_msec)
{
  if ( _mode == MODE_PLAY ) {
    // Bullet move
    if ( _p1.bullet()->move(cur_msec) ) {
    }
    // Enemy
    if ( _e1.move(cur_msec) ) {
      _e1.print("loop()");
      if ( _e1.x() == 0 ) {
	// Game Over
	Serial.println("_score=" + String(_score));
	set_mode(MODE_SCORE);
      }
    }
    // Bullet
    if ( _p1.bullet()->val() != Bullet::VAL_NULL && _e1.size() > 0 ) {
      if ( _p1.bullet()->x() == _e1.x() ) {
	if ( _p1.bullet()->val() == _e1.val(0) ) {
	  // hit !
	  _e1.hit();
	  _score++;
	  Serial.println("hit!! _score=" + String(_score));
	  if ( _e1.interval() > 500 ) {
	    _e1.set_interval(_e1.interval() - 100);
	    Serial.println("_e1.interval()=" + String(_e1.interval()));
	  }
	}
	_p1.bullet_delete();
      }
    }
  } else if ( _mode == MODE_SCORE ) {
    if ( cur_msec - score_start_msec() >= DISP_SCORE_MSEC ) {
      set_mode(MODE_END);
    }
  }

  display();
}
//-------------------------------------------
void Game1::displayGame()
{
  _vfd->setValue(0, _p1.val());

  for (int i = 0; i < _e1.size(); i++) {
    _vfd->setValue(_vfd->digitN() - _e1.size() + i, _e1.val(i));
  }
  if ( _p1.bullet()->val() != Bullet::VAL_NULL ) {
    _vfd->setValue(_p1.bullet()->x(), _p1.bullet()->val());
  }
}
//-------------------------------------------
void Game1::displayScore()
{
  uint8_t	num;
  uint8_t	val		= VFD::VAL_NULL;
  boolean	blink_flag	= true;

  if ( _mode == MODE_SCORE ) {
    blink_flag = true;
  } else {
    blink_flag = false;
  }
  
  for (int i=0; i < _vfd->digitN(); i++) {
    num = _score / int(pow(10, 5 - i)) % 10;
    //Serial.println(String(i) + ":" + String(num) + ":" + String(val));
    if ( val != VFD::VAL_NULL || num != 0 || i == _vfd->digitN() - 1 ) {
      val = num;
    }
    _vfd->set(i, val, false, blink_flag);
  } // for
}
//-------------------------------------------
void Game1::display()
{
  _vfd->clear();

  switch ( _mode ) {
  case MODE_PLAY:
    displayGame();
    break;
  case MODE_SCORE:
  case MODE_END:
    displayScore();
    break;
  default:
    break;
  } // switch ( _mode )

  _vfd->display();
}
//-------------------------------------------
mode_t Game1::mode()
{
  return _mode;
}
//-------------------------------------------
void Game1::set_mode(mode_t mode)
{
  if ( mode == MODE_SCORE ) {
    set_score_start_msec(millis());
  }
  _mode = mode;
}

//-------------------------------------------
unsigned long Game1::score()
{
  return _score;
}
unsigned long Game1::score_start_msec()
{
  return _score_start_msec;
}
void Game1::set_score_start_msec(unsigned long msec)
{
  _score_start_msec = msec;
}

//-------------------------------------------
Player *Game1::p1()
{
  return &_p1;
}
//-------------------------------------------
Enemy *Game1::e1()
{
  return &_e1;
}
