/****************************************************************************

 This file is part of the GLC-lib library.
 Copyright (C) 2005-2008 Laurent Ribon (laumaya@users.sourceforge.net)
 Version 1.1.0, packaged on March, 2009.

 http://glc-lib.sourceforge.net

 GLC-lib is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 GLC-lib is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with GLC-lib; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

*****************************************************************************/

//! \file glc_circle.h interface for the GLC_Circle class.

#ifndef GLC_CIRCLE_H_
#define GLC_CIRCLE_H_

#include "glc_vbogeom.h"
#include "glc_simplegeomengine.h"

//////////////////////////////////////////////////////////////////////
//! \class GLC_Circle
/*! \brief GLC_Circle : OpenGL 3D Circle*/

/*! An GLC_Circle is a wire geometry composed of 3d lines \n
 * It can be an entire circle or an arc.
 * */
//////////////////////////////////////////////////////////////////////
class GLC_Circle : public GLC_VboGeom
{
//////////////////////////////////////////////////////////////////////
/*! @name Constructor / Destructor */
//@{
//////////////////////////////////////////////////////////////////////
public:

	//! Construct an GLC_Circle
	/*! By default, discretion is set to #GLC_DISCRET*/
	GLC_Circle(const double &dRadius, double Angle= 2 * glc::PI);

	//! Copy constructor
	GLC_Circle(const GLC_Circle& sourceCircle);

	//! Destructor
	virtual ~GLC_Circle();

//@}

//////////////////////////////////////////////////////////////////////
/*! \name Get Functions*/
//@{
//////////////////////////////////////////////////////////////////////
public:

	//! Return Circle Discretion
	int getDiscretion(void) const;

	//! Return Circle radius
	double getRadius(void) const;

	//! return Circle diameter
	double getDiameter(void) const;

	//! return the circle bounding box
	virtual GLC_BoundingBox& boundingBox(void);

	//! Return a copy of the geometry
	virtual GLC_VboGeom* clone() const;
//@}

//////////////////////////////////////////////////////////////////////
/*! \name Set Functions*/
//@{
//////////////////////////////////////////////////////////////////////
public:
	//! Set Circle diameter
	/*! Diameter must be > 2 * EPSILON*/
	void setDiameter(double D);

	//! Set Circle Radius
	/*! Radius must be > EPSILON*/
	void setRadius(double R);

	//! Set Circle discret
	/*! TargetDiscret must be > 0
	 *  if TargetDiscret < 6 discretion is set to 6*/
	void setDiscretion(int TargetDiscret);

	//! Set Circle Angle
	/*! AngleRadians must be > EPSILON and < 2 PI*/
	void setAngle(double AngleRadians);	// Angle in Radians

//@}

//////////////////////////////////////////////////////////////////////
/*! \name OpenGL Functions*/
//@{
//////////////////////////////////////////////////////////////////////
private:

	//! Virtual interface for OpenGL Geometry set up.
	/*! This Virtual function is implemented here.\n
	 *  Throw GLC_OpenGlException*/
	virtual void glDraw(bool transparent= false);

//@}

//////////////////////////////////////////////////////////////////////
// private members
//////////////////////////////////////////////////////////////////////
private:
	//! Circle Radius
	double m_Radius;

	//! Circle Discretion
	int m_nDiscret;

	//! Angle of circle in radians
	double m_dAngle;

	//! Circle Step
	GLuint m_Step;

	//! Geom engine
	GLC_SimpleGeomEngine m_SimpleGeomEngine;

};
#endif //GLC_CIRCLE_H_