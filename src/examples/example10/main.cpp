/****************************************************************************
 This file is part of the documentation of GLC-lib library.
 Copyright (C) 2012 Laurent Ribon (laumaya@users.sourceforge.net)
 http://glc-lib.sourceforge.net

 GLC-lib is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This file is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 http://www.fsf.org/licensing/licenses/info/GPLv2.html and
 http://www.gnu.org/copyleft/gpl.html.
*****************************************************************************/

#include "GLCGraphicsView.h"
#include "GLCScene.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    GLCGraphicsView view;
    view.setScene(new GLCScene());
    view.show();

    view.resize(800, 600);

    return app.exec();
}
