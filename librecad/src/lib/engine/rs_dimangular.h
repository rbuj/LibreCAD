/****************************************************************************
**
** This file is part of the LibreCAD project, a 2D CAD program
**
** Copyright (C) 2010 R. van Twisk (librecad@rvt.dds.nl)
** Copyright (C) 2001-2003 RibbonSoft. All rights reserved.
**
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file gpl-2.0.txt included in the
** packaging of this file.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
**
** This copyright notice MUST APPEAR in all copies of the script!
**
**********************************************************************/


#ifndef RS_DIMANGULAR_H
#define RS_DIMANGULAR_H

#include "rs_dimension.h"

/**
 * Holds the data that defines a angular dimension entity.
 */
struct RS_DimAngularData {
	/**
	 * Default constructor
	 */
	RS_DimAngularData();

	/**
	 * Constructor with initialisation.
	 *
	 * @param definitionPoint Definition point of the angular dimension.
	 * @param leader Leader length.
	 */
	RS_DimAngularData(const RS_Vector& definitionPoint1,
					  const RS_Vector& definitionPoint2,
					  const RS_Vector& definitionPoint3,
					  const RS_Vector& definitionPoint4);

	/** Definition point 1. */
	RS_Vector definitionPoint1;
	/** Definition point 2. */
	RS_Vector definitionPoint2;
	/** Definition point 3. */
	RS_Vector definitionPoint3;
	/** Definition point 4. */
	RS_Vector definitionPoint4;
};

std::ostream& operator << (std::ostream& os,
									  const RS_DimAngularData& dd);


/**
 * Class for angular dimension entities.
 *
 * @author Andrew Mustun
 */
class RS_DimAngular : public RS_Dimension {
public:
    RS_DimAngular(RS_EntityContainer* parent,
                 const RS_DimensionData& d,
                 const RS_DimAngularData& ed);

	RS_Entity* clone() const override;

    /**	@return RS2::EntityDimAngular */
	RS2::EntityType rtti() const override{
        return RS2::EntityDimAngular;
    }

    /**
     * @return Copy of data that defines the angular dimension.
     * @see getData()
     */
    RS_DimAngularData getEData() const {
        return edata;
    }

	QString getMeasuredLabel() override;
    double getAngle();
	RS_Vector getCenter() const override;
        bool getAngles(double& ang1, double& ang2, bool& reversed,
                RS_Vector& p1, RS_Vector& p2);

	void updateDim(bool autoText=false) override;

    RS_Vector getDefinitionPoint1() {
        return edata.definitionPoint1;
    }
    RS_Vector getDefinitionPoint2() {
        return edata.definitionPoint2;
    }
    RS_Vector getDefinitionPoint3() {
        return edata.definitionPoint3;
    }
    RS_Vector getDefinitionPoint4() {
        return edata.definitionPoint4;
    }
	void move(const RS_Vector& offset) override;
	   void rotate(const RS_Vector& center, const double& angle) override;
	   void rotate(const RS_Vector& center, const RS_Vector& angleVector) override;
	   void scale(const RS_Vector& center, const RS_Vector& factor) override;
	   void mirror(const RS_Vector& axisPoint1, const RS_Vector& axisPoint2) override;

    friend std::ostream& operator << (std::ostream& os,
                                      const RS_DimAngular& d);

protected:
    /** Extended data. */
    RS_DimAngularData edata;
};

#endif
