/***************************************************************************
                          kchooseimportexportdlg.h  -  description
                             -------------------
    begin                : Thu Jul 12 2001
    copyright            : (C) 2000-2001 by Michael Edwardes
    email                : mte@users.sourceforge.net
                             Javier Campos Morales <javi_c@users.sourceforge.net>
                             Felix Rodriguez <frodriguez@users.sourceforge.net>
                             John C <thetacoturtle@users.sourceforge.net>
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef KCHOOSEIMPORTEXPORTDLG_H
#define KCHOOSEIMPORTEXPORTDLG_H

// ----------------------------------------------------------------------------
// QT Includes

#include <QDialog>

// ----------------------------------------------------------------------------
// KDE Includes

// ----------------------------------------------------------------------------
// Project Includes

/**
  *@author Michael Edwardes
  */
class KChooseImportExportDlg : public QDialog
{
  Q_OBJECT
private:
  void readConfig();
  void writeConfig();
  QString m_lastType;

protected slots:
  void slotTypeActivated(const QString& text);

public:
  explicit KChooseImportExportDlg(int type, QWidget *parent = 0);
  ~KChooseImportExportDlg();
  QString importExportType();

private:
  /// \internal d-pointer class.
  struct Private;
  /// \internal d-pointer instance.
  Private* const d;
};

#endif
