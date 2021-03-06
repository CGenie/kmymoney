/***************************************************************************
                         newpaymentswizardpage  -  description
                            -------------------
   begin                : Sun Jul 4 2010
   copyright            : (C) 2010 by Fernando Vilas
   email                : kmymoney-devel@kde.org
***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef NEWPAYMENTSWIZARDPAGE_H
#define NEWPAYMENTSWIZARDPAGE_H

// ----------------------------------------------------------------------------
// QT Includes

#include <QWizardPage>

// ----------------------------------------------------------------------------
// KDE Includes

// ----------------------------------------------------------------------------
// Project Includes

#include "ui_newpaymentswizardpagedecl.h"

/**
 * This class implements the New Payments page of the
 * @ref KNewLoanWizard.
 */
class NewPaymentsWizardPageDecl : public QWizardPage, public Ui::NewPaymentsWizardPageDecl
{
public:
  NewPaymentsWizardPageDecl(QWidget *parent) : QWizardPage(parent) {
    setupUi(this);
  }
};

class NewPaymentsWizardPage : public NewPaymentsWizardPageDecl
{
  Q_OBJECT
public:
  explicit NewPaymentsWizardPage(QWidget *parent = 0);

};

#endif
