/********************************************************************************\
 **                                                                              **
 **  Copyright (C) 2010 Alasdair Morrison <tgmg@g-java.com>, Josh Ventura        **
 **  Copyright (C) 2013 Robert B. Colton                                         **
 **                                                                              **
 **  This file is a part of the ENIGMA Development Environment.                  **
 **                                                                              **
 **                                                                              **
 **  ENIGMA is free software: you can redistribute it and/or modify it under the **
 **  terms of the GNU General Public License as published by the Free Software   **
 **  Foundation, version 3 of the license or any later version.                  **
 **                                                                              **
 **  This application and its source code is distributed AS-IS, WITHOUT ANY      **
 **  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS   **
 **  FOR A PARTICULAR PURPOSE. See the GNU General Public License for more       **
 **  details.                                                                    **
 **                                                                              **
 **  You should have recieved a copy of the GNU General Public License along     **
 **  with this code. If not, see <http://www.gnu.org/licenses/>                  **
 **                                                                              **
 **  ENIGMA is an environment designed to create games and other programs with a **
 **  high-level, fully compilable language. Developers of ENIGMA or anything     **
 **  associated with ENIGMA are in no way responsible for its users or           **
 **  applications created by its users, or damages caused by the environment     **
 **  or programs made in the environment.                                        **
 **                                                                              **
 \********************************************************************************/

#include "GLtextures.h"
#ifdef DEBUG_MODE
  #include <string>
  #include "libEGMstd.h"
  #include "Widget_Systems/widgets_mandatory.h"
  #define get_background(bck2d,back)\
    if (back < 0 or size_t(back) >= enigma::background_idmax or !enigma::backgroundstructarray[back]) {\
      show_error("Attempting to draw non-existing background " + toString(back), false);\
      return;\
    }\
    const enigma::background *const bck2d = enigma::backgroundstructarray[back];
  #define get_backgroundnv(bck2d,back,r)\
    if (back < 0 or size_t(back) >= enigma::background_idmax or !enigma::backgroundstructarray[back]) {\
      show_error("Attempting to draw non-existing background " + toString(back), false);\
      return r;\
    }\
    const enigma::background *const bck2d = enigma::backgroundstructarray[back];
#else
  #define get_background(bck2d,back)\
    const enigma::background *const bck2d = enigma::backgroundstructarray[back];
  #define get_backgroundnv(bck2d,back,r)\
    const enigma::background *const bck2d = enigma::backgroundstructarray[back];
#endif

int background_get_texture(int backId);
int background_get_width(int backId);
int background_get_height(int backId);
double background_get_texture_width_factor(int backId);
double background_get_texture_height_factor(int backId);
void draw_background(int back, double x, double y);
void draw_background_stretched(int back, double x, double y, double w, double h);
void draw_background_part(int back,double left,double top,double width,double height,double x,double y);
void draw_background_tiled(int back,double x,double y);
void draw_background_tiled_area(int back,double x,double y,double x1,double y1,double x2,double y2);
void draw_background_ext(int back,double x,double y,double xscale,double yscale,double rot,int color,double alpha);
void draw_background_stretched_ext(int back,double x,double y,double w,double h,int color,double alpha);
void draw_background_part_ext(int back,double left,double top,double width,double height,double x,double y,double xscale,double yscale,int color,double alpha);
void draw_background_tiled_ext(int back,double x,double y,double xscale,double yscale,int color,double alpha);
void draw_background_tiled_area_ext(int back,double x,double y,double x1,double y1,double x2,double y2, double xscale, double yscale, int color, double alpha);
void draw_background_general(int back,double left,double top,double width,double height,double x,double y,double xscale,double yscale,double rot,int c1,int c2,int c3,int c4,double a1,double a2,double a3,double a4);