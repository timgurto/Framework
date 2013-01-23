// (C) 2009, 2010 Tim Gurto

#include "SDL.h"
#include "util.h"
#include "Point.h"

Point::Point(const SDL_Rect &original):
x(original.x),
y(original.y){}

Point::Point(pixels_t xCoord, pixels_t yCoord):
x(xCoord),
y(yCoord)
{}

Point::operator SDL_Rect(){
   return makeRect(x, y);
}

Point &Point::operator=(const SDL_Rect &rhs){
   this->x = rhs.x;
   this->y = rhs.y;
   return *this;
}

Point Point::operator+(const Point &rhs) const{
   return Point(x + rhs.x, y + rhs.y);
}

Point &Point::operator+=(const Point &rhs){
   x += rhs.x;
   y += rhs.y;
   return *this;
}

Point Point::operator-(const Point &rhs) const{
   return Point(x - rhs.x, y - rhs.y);
}

Point &Point::operator-=(const Point &rhs){
   x -= rhs.x;
   y -= rhs.y;
   return *this;
}

Point Point::operator*(double rhs) const{
   return Point(pixels_t(x * rhs),
                pixels_t(y * rhs));
}

Point Point::operator/(double rhs) const{
   //treat 0 as 1
   if (rhs == 0)
      return *this;

   return Point(pixels_t(x / rhs),
                pixels_t(y / rhs));
}

SDL_Rect Point::operator-(const SDL_Rect &rhs) const{
   return makeRect(x-rhs.x, y-rhs.y, -1 * rhs.w, -1 * rhs.h);
}

SDL_Rect Point::operator+(const SDL_Rect &rhs) const{
   return makeRect(x+rhs.x, y+rhs.y, rhs.w, rhs.h);
}

SDL_Rect operator+(SDL_Rect lhs, const Point &rhs){
   lhs.x += rhs.x;
   lhs.y += rhs.y;
   return lhs;
}

SDL_Rect operator-(SDL_Rect lhs, const Point &rhs){
   lhs.x -= rhs.x;
   lhs.y -= rhs.y;
   return lhs;
}

bool Point::operator<(const Point &rhs) const{
   if (x < rhs.x)
      return true;
   if (x > rhs.x)
      return false;
   return (y < rhs.y);
}

bool Point::operator==(const Point &rhs) const{
   return
      x == rhs.x &&
      y == rhs.y;
}

bool Point::operator!=(const Point &rhs) const{
   return !(*this == rhs);
}

bool Point::operator==(const SDL_Rect &rhs) const{
   return
      x == rhs.x &&
      y == rhs.y;
}

bool operator==(const SDL_Rect &lhs, const Point &rhs){
   return rhs == lhs;
}