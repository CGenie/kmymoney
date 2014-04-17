/*
 * This file is part of KMyMoney, A Personal Finance Manager for KDE
 * Copyright (C) 2014 Christian Dávid <christian-david@web.de>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NATIONALACCOUNTID_H
#define NATIONALACCOUNTID_H

#include "mymoney/payeeidentifier/payeeidentifier.h"
#include "nationalaccountidmacros.h"

namespace payeeIdentifiers {

class NATIONALACCOUNT_IDENTIFIER_EXPORT nationalAccount : public payeeIdentifier
{
public:
  PAYEEIDENTIFIER_ID(nationalAccount, "org.kmymoney.payeeIdentifier.national");
  
  virtual bool isValid() const;
  virtual bool operator==(const payeeIdentifier& other) const;
  bool operator==(const nationalAccount& other) const;
  
  nationalAccount* clone() const { return new nationalAccount(*this); }
  nationalAccount* createFromXml(const QDomElement& element) const;
  void writeXML(QDomDocument& document, QDomElement& parent) const;
  
  QString bankCode() const { return m_bankCode; }
  QString accountNumber() const { return m_accountNumber; }
  
  /** @todo implement */
  QString bankName() const { return QString(); }
  
  void setBankCode( const QString& bankCode ) { m_bankCode = bankCode; }
  void setAccountNumber( const QString& accountNumber ) { m_accountNumber = accountNumber; }

private:
  QString m_bankCode;
  QString m_accountNumber;
};

} // namespace payeeIdentifiers

#endif // NATIONALACCOUNTID_H
