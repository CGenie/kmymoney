/***************************************************************************
                             lua.h
                             -------------------
    begin                : Mon Mar 21 2016
    copyright            : (C) 2016 by Przemek Kaminski
    email                : cgenie@gmail.com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef LUAPLUGIN_H
#define LUAPLUGIN_H

// ----------------------------------------------------------------------------
// KDE Includes

// ----------------------------------------------------------------------------
// QT Includes

#include <QList>
#include <QStringList>

// Project Includes

#include "kmymoneyplugin.h"

//class LuaDialog;

class LuaPlugin : public KMyMoneyPlugin::Plugin
{
  Q_OBJECT

public:
  explicit LuaPlugin(QObject* parent, const QVariantList&);
  ~LuaPlugin();

  KAction*          m_action;

protected slots:
  void openLuaDialog();

//public slots:
  //bool slotGetStatement(MyMoneyStatement& s);

//protected slots:
//  void slotImportFile(void);

protected:
  void createActions(void);
  //bool importStatement(const MyMoneyStatement& s);
  //void processStatement(const MyMoneyStatement& s);
};

#endif
