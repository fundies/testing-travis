/********************************************************************************\
**                                                                              **
**  Copyright (C) 2008 Josh Ventura                                             **
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


namespace rect_packer
{
  struct pvrect {
    int x,y,w,h, placed;
    pvrect(); pvrect(int a,int b,int c,int d,int e);
  };
  
  struct rectpnode
  {
    rectpnode* child[2];
    int x,y,wid,hgt;
    int c;
    rectpnode();
    rectpnode(int xx,int yy,int w,int h,rectpnode* c1=NULL,rectpnode* c2=NULL);
    void rect(int xx, int yy, int w, int h);
  };
  
  void rncopy(rectpnode *h, pvrect *boxes, unsigned char c);
  rectpnode *rninsert(rectpnode* who, unsigned char c, pvrect* boxes);
  rectpnode *expand(rectpnode* who, int w, int h);
}

