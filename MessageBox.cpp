// (C) 2010 Tim Gurto

#include <cassert>
#include "MessageBox.h"
#include "globals.h"
#include "util.h"
#include "Surface.h"

namespace Game {

MessageBox::MessageBox(SDL_Color color,
                       pixels_t x, pixels_t y,
                       pixels_t margin,
                       Surface &background,
                       const std::string &fontName,
                       int fontSize,
                       bool accountForHeight,
                       bool visible):
color_(color),
x_(x),
y_(y),
margin_(margin),
background_(background),
visible_(visible),
font_(TTF_OpenFont(fontName.c_str(), fontSize)){
   assert (font_);
   //font height
   int fontHeight = TTF_FontHeight(font_);
   height_ = fontHeight + 2 * margin_;
   if (accountForHeight)
      y_ -= fontHeight;
}

void MessageBox::draw() const{
   if (visible_)
      if (message_ != ""){
         assert (screenBuf);

         //message surface
         Surface text(font_, message_, color_);
         pixels_t width = text->clip_rect.w + margin_;

         //background
         if (background_) {
            SDL_Rect rect1 = makeRect(x_ - margin_, y_ - margin_);
            SDL_Rect rect2 = makeRect(0, 0, width, height_);
            background_.draw(screenBuf,
                             &rect1,
                             &rect2);
         }

         //message
         SDL_Rect rect = makeRect(x_ + margin_, y_ + margin_);
         text.draw(screenBuf, &rect);
      }
}


void MessageBox::clear(){
   message_.clear();
}

void MessageBox::toggleVisibility(){
   visible_ = !visible_;
}

} // namespace Game
