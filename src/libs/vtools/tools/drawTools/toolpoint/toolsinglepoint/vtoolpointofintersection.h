/************************************************************************
 **
 **  @file   vtoolpointofintersection.h
 **  @author Roman Telezhynskyi <dismine(at)gmail.com>
 **  @date   November 15, 2013
 **
 **  @brief
 **  @copyright
 **  This source code is part of the Valentine project, a pattern making
 **  program, whose allow create and modeling patterns of clothing.
 **  Copyright (C) 2013-2015 Valentina project
 **  <https://bitbucket.org/dismine/valentina> All Rights Reserved.
 **
 **  Valentina is free software: you can redistribute it and/or modify
 **  it under the terms of the GNU General Public License as published by
 **  the Free Software Foundation, either version 3 of the License, or
 **  (at your option) any later version.
 **
 **  Valentina is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **
 **  You should have received a copy of the GNU General Public License
 **  along with Valentina.  If not, see <http://www.gnu.org/licenses/>.
 **
 *************************************************************************/

#ifndef VTOOLPOINTOFINTERSECTION_H
#define VTOOLPOINTOFINTERSECTION_H

#include "vtoolsinglepoint.h"

/**
 * @brief The VToolPointOfIntersection class tool for creation point intersection two lines.
 */
class VToolPointOfIntersection : public VToolSinglePoint
{
    Q_OBJECT
public:
    VToolPointOfIntersection(VAbstractPattern *doc, VContainer *data, const quint32 &id, const quint32 &firstPointId,
                             const quint32 &secondPointId, const Source &typeCreation,
                             QGraphicsItem * parent = nullptr);
    virtual void setDialog();
    static VToolPointOfIntersection *Create(DialogTool *dialog, VMainGraphicsScene  *scene, VAbstractPattern *doc,
                                            VContainer *data);
    static VToolPointOfIntersection *Create(const quint32 _id, const QString &pointName, const quint32 &firstPointId,
                                            const quint32 &secondPointId, const qreal &mx, const qreal &my,
                                            VMainGraphicsScene *scene, VAbstractPattern *doc, VContainer *data,
                                            const Document &parse, const Source &typeCreation);
    static const QString ToolType;
    virtual int  type() const {return Type;}
    enum { Type = UserType + static_cast<int>(Tool::PointOfIntersection) };

    quint32 GetFirstPointId() const;
    void    SetFirstPointId(const quint32 &value);

    quint32 GetSecondPointId() const;
    void    SetSecondPointId(const quint32 &value);

    virtual void ShowVisualization(bool show);
protected:
    virtual void RemoveReferens();
    virtual void contextMenuEvent ( QGraphicsSceneContextMenuEvent * event );
    virtual void SaveDialog(QDomElement &domElement);
    virtual void SaveOptions(QDomElement &tag, QSharedPointer<VGObject> &obj);
    virtual void ReadToolAttributes(const QDomElement &domElement);
    virtual void SetVisualization();
private:
    Q_DISABLE_COPY(VToolPointOfIntersection)
    /** @brief firstPointId id first line point. */
    quint32       firstPointId;

    /** @brief secondPointId id second line point. */
    quint32       secondPointId;
};

#endif // VTOOLPOINTOFINTERSECTION_H
