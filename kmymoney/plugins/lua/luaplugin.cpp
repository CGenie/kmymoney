/***************************************************************************
                            luaplugin.cpp
                       (based on ofximporterplugin.cpp)
                             -------------------
    begin                : Mon Jan 21 2016
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

#include "luaplugin.h"
#include <assert.h>
// ----------------------------------------------------------------------------
// QT Includes

#include <QFile>

// ----------------------------------------------------------------------------
// KDE Includes

#include <KPluginFactory>
#include <KDebug>
#include <KFile>
#include <KUrl>
#include <KAction>
#include <KMessageBox>
#include <KActionCollection>
#include <KStandardDirs>
#include <KSharedConfig>
#include <KLocale>

// ----------------------------------------------------------------------------
// Project Includes

#include "mymoneystatementreader.h"
#include "mymoneystatement.h"
//#include "csvdialog.h"
//#include "investprocessing.h"

K_PLUGIN_FACTORY(LuaFactory, registerPlugin<LuaPlugin>();)
K_EXPORT_PLUGIN(LuaFactory("kmm_plugin"))

LuaPlugin::LuaPlugin(QObject *parent, const QVariantList&) :
    KMyMoneyPlugin::Plugin(parent, "lua"/*must be the same as X-KDE-PluginInfo-Name*/)
{
  setComponentData(LuaFactory::componentData());
  setXMLFile("kmm_lua.rc");
  createActions();
// For information, announce that we have been loaded.
  qDebug("KMyMoney lua plugin loaded");
}

LuaPlugin::~LuaPlugin()
{
}

void LuaPlugin::createActions(void)
{
  m_action = actionCollection()->addAction("tools_lua");
  m_action->setText(i18n("Lua..."));
  connect(m_action, SIGNAL(triggered(bool)), this, SLOT(openLuaDialog()));
}

void LuaPlugin::openLuaDialog(void)
{
    //LuaDialog *luaDialog = new LuaDialog;

    qDebug("Lua dialog opening");
}

/*
void CsvImporterPlugin::slotImportFile(void)
{
  m_action->setEnabled(false);
  CSVDialog *csvImporter = new CSVDialog;
  csvImporter->m_plugin = this;
  csvImporter->init();

  csvImporter->setWindowTitle(i18nc("CSV Importer dialog title", "CSV Importer"));

  connect(csvImporter, SIGNAL(statementReady(MyMoneyStatement&)), this, SLOT(slotGetStatement(MyMoneyStatement&)));
  csvImporter->show();
  m_action->setEnabled(false);//  don't allow further plugins to start while this is open
}

bool CsvImporterPlugin::slotGetStatement(MyMoneyStatement& s)
{
  return statementInterface()->import(s);
}
*/

