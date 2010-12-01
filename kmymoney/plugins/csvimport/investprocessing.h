/***************************************************************************
                        investprocessing.h
                        ------------------
begin                 : Sat Jan 01 2010
copyright             : (C) 2010 by Allan Anderson
email                 : aganderson@ukonline.co.uk
****************************************************************************/

/***************************************************************************

*   This program is free software; you can redistribute it and/or modify   *
*   it under the terms of the GNU General Public License as published      *
*   by the Free Software Foundation; either version 2 of the License,      *
*   or  (at your option) any later version.                                *
*                                                                          *
****************************************************************************/


#ifndef INVESTPROCESSING_H
#define INVESTPROCESSING_H

// ----------------------------------------------------------------------------
// QT Headers

#include <QtCore/QDate>
#include <QtCore/QTextStream>
#include <QtCore/QFile>
// ----------------------------------------------------------------------------
// KDE Headers
#include <KUrl>
// ----------------------------------------------------------------------------
// Project Headers

#include <mymoneystatement.h>
#include "ui_investmentdlgdecl.h"

#define invMAXCOL 14    //                 maximum no. of columns (arbitrary value)

class ConvertDate;
class CsvImporterDlg;
class InvestmentDlg;
class MyMoneyStatement;
class RedefineDlg;

class InvestProcessing : public QObject
{
  Q_OBJECT

public:
  InvestProcessing();
  ~InvestProcessing();

  struct qifInvestData {

    QString      memo;
    QString      price;
    QString      quantity;
    QString      amount;
    QString      fee;
    QString      payee;
    QString      security;
    QString      brokerageAccnt;
    QString      type;
    QDate        date;
  }              m_trInvestData;

  InvestmentDlg* m_investDlg;

  QString        m_inFileName;
  QString        m_csvPath;

  /**
  * This method is called after startup, to initialise some parameters.
  */
  void           init();

  /**
  * This method is called to redraw the window according to the number of
  * columns and rows to be displayed.
  */
  void           updateScreen();

public:
signals:
  /**
  * This signal is raised when the plugin has completed a transaction.  This
  * then needs to be processed by MyMoneyStatement.
  */
  void           statementReady(MyMoneyStatement&);

public slots:

  /**
  * This method is called when the user clicks 'Open File', and opens
  * a file selector dialog.
  */
  void           fileDialog();

  /**
  * This method is called when the Date column is activated.
  * It will validate the column selection.
  */
  void           dateColumnSelected(int);

  /**
  * This method is called when the user clicks 'Encoding' and selects an
  * encoding setting.  The file is re-read with the corresponding codec.
  */
  void           encodingChanged();

  /**
  * This method is called when the user selects a new field delimiter.  The
  * input file is reread using the current delimiter.
  */
  void           fieldDelimiterChanged();

  /**
  * This method is called if the Fee column is activated.  The fee column may
  * contain either a value or a percentage. The user needs to set the 'Fee is
  * percentage' check box appropriately.  Caution may be needed here, as the fee
  * may already have been taken into account in the price.
  */
  void           feeColumnSelected(int);

  /**
  * This method is called when the Memo column is activated.
  * Multiple columns may be selected sequentially.
  */
  void           memoColumnSelected(int);

  /**
  * This method is called when the Quantity column is activated.
  * It will validate the column selection.
  */
  void           quantityColumnSelected(int);

  /**
  * This method is called when the Price column is activated.
  * It will validate the column selection.
  */
  void           priceColumnSelected(int);

  /**
  * This method is called when the Amount column is activated.
  * It will validate the column selection.
  */
  void           amountColumnSelected(int);

  /**
  * This method is called when the user clicks Accept. It performs further
  * validity checks on the user's choices, then redraws the required rows.
  * Finally, it rereads the file, which this time will result in the import
  * actually taking place.
  */
  void           acceptClicked(bool checked);

  /**
  * This method is called when the user clicks the Date button and selects
  * the date format for the input file.
  */
  void           dateFormatSelected(int dF);

  /**
  * This method is called should the user click 'Save as QIF'. A File Selection
  * dialog is presented and the data is output in QIF format.
  */
  void           saveAs();

  /**
  * This method is called when the user selects the start line.  The requested
  * start line  value is saved.
  */
  void           startLineChanged();

  /**
  * This method is called when the user selects the end line.  The requested
  * end line  value is saved, to be used on import.
  */
  void           endLineChanged();

  /**
  * This method is called when the activity 'Type/Action' column is activated.
  * It will validate the column selection.
  */
  void           typeColumnChanged(int);

private:

  /**
  * This method is called when the user clicks 'Clear selections', in order to
  * clear incorrect column number entries.
  */
  void           clearColumnNumbers();

  /**
  * This method is called when the user clicks 'Clear selections', in order to
  * clear incorrect column number entries.  Also called on initialisation.
  */
  void           clearSelectedFlags();

  /**
  * This method is called during import, to convert the QString activity type
  * to a MyMoneyStatement::Transaction::EAction& convType, which is added to
  * the transaction about to be imported.
  */
  void           convertType(const QString&, MyMoneyStatement::Transaction::EAction&);

  /**
  * This method is called when a date cannot be recognised  and the user
  * cancels the statement import. It will disable the UI elements for column
  * selection, neccessitating file reselection.
  */
  void           disableInputs();

  /**
  * This method is called on opening the input file.
  * It will display a line in the UI table widget.
  */
  void           displayLine(const QString&);

  /**
  * This method is called when an input file has been selected.
  * It will enable the UI elements for column selection.
  */
  void           enableInputs();

  /**
  * This method is called during input.  It builds the
  * MyMoneyStatement, ready for importing.
  */
  void           investCsvImport(MyMoneyStatement&);

  /**
  * This method is called initially after an input file has been selected.
  * It will call other routines to display file content and to complete the
  * statement import. It will also be called to reposition the file after row
  * deletion, or to reread following encoding or delimiter change.
  */
  void           readFile(const QString& fname, int skipLines);

  /**
  * This method is called on opening, to load settings from the resource file.
  */
  void           readSettings();

  /**
  * This method is called on opening the plugin.
  * It will populate a list with all available codecs.
  */
  void           findCodecs();

  /**
  * This method is called during input.  It validates the action types
  * in the input file, and assigns appropriate QString types.
  */
  int            processActionType(QString&);

  /**
  * This method is called when the user clicks 'Accept'.
  * It will evaluate an input line and prepare it to be added to a statement,
  * and to a QIF file, if required.
  */
  int            processInvestLine(const QString& iBuff);

  /**
  * This method is called during input if a brokerage type activity is found.
  * It will request user input of the brokerage/current account to be used, and
  * also of the column defining the payee/detail.
  */
  QString        getAccountName(QString);

  /**
  * This method is called during input if a brokerage type activity is found.
  * It will request user input of the column defining the payee/detail.
  */
  int            getColumnNumber(QString column);

  /**
  * This method is called on opening the plugin.
  * It will add all codec names to the encoding combobox.
  */
  void           setCodecList(const QList<QTextCodec *> &list);

  bool           m_amountSelected;
  bool           m_brokerage;
  bool           m_brokerageItems;
  bool           m_importNow;
  bool           m_dateSelected;
  bool           m_feeSelected;
  bool           m_memoSelected;
  bool           m_priceSelected;
  bool           m_quantitySelected;
  bool           m_typeSelected;

  int            m_dateFormatIndex;
  int            m_maxColumnCount;
  int            m_maxWidth;
  int            m_payeeColumn;
  int            m_amountColumn;
  int            m_width;
  int            m_endLine;
  int            m_startLine;
  int            m_row;
  int            m_height;
  int            m_lastColumn;

  QString        m_accountName;
  QString        m_brokerBuff;
  QString        m_columnType[invMAXCOL];
  QString        m_dateFormat;
  QString        m_fieldDelimiter_char;
  QString        m_inBuffer;
  QString        m_outBuffer;
  QString        m_tempBuffer;

  QList<QTextCodec *>   m_codecs;

  QStringList    m_shrsinList;
  QStringList    m_divXList;
  QStringList    m_brokerageList;
  QStringList    m_reinvdivList;
  QStringList    m_buyList;
  QStringList    m_sellList;
  QStringList    m_removeList;
  QStringList    m_dateFormats;

  KUrl           m_url;
  QFile*         m_inFile;

private slots:

  /**
  * This method is called when 'Go to Banking' is clicked.  The current
  * Investment window will be hidden and the Banking dialog will be shown.
  */
  void           bankingSelected();

  /**
  * This method is called when the user clicks 'Clear selections'.
  * All column selections are cleared.
  */
  void           clearColumnsSelected();
};
#endif // INVESTPROCESSING_H