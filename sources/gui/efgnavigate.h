//
// $Source$
// $Revision$
// $Date$
//
// DESCRIPTION:
// Interface to navigation window for extensive forms
// 
// This file is part of Gambit
// Copyright (c) 2002, The Gambit Project
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
//

#ifndef EFGNAVIGATE_H
#define EFGNAVIGATE_H

#include "wx/grid.h"
#include "efgshow.h"
#include "gamedoc.h"

class EfgNavigateWindow : public wxGrid {
private:
  gbtGameDocument *m_doc;

  bool IsEfgView(void) const { return true; }
  bool IsNfgView(void) const { return false; }

public:
  EfgNavigateWindow(gbtGameDocument *p_doc, wxWindow *p_parent);
  virtual ~EfgNavigateWindow() { }

  void OnUpdate(void);
};

class gbtEfgNavigateFrame : public wxFrame, public gbtGameView {
private:
  EfgNavigateWindow *m_grid;

  // Event handlers
  void OnClose(wxCloseEvent &);

  // Overriding view members
  bool IsEfgView(void) const { return true; }
  bool IsNfgView(void) const { return false; }
  void OnUpdate(gbtGameView *);

public:
  gbtEfgNavigateFrame(gbtGameDocument *p_doc, wxWindow *p_parent);
  virtual ~gbtEfgNavigateFrame();

  DECLARE_EVENT_TABLE()
};

#endif  // EFGNAVIGATE_H
