include_directories( ${KMyMoney_SOURCE_DIR}/libkdchart/include)

set (libreports_a_SOURCES
  kreportchartview.cpp
  reportaccount.cpp
  listtable.cpp
  objectinfotable.cpp
  pivotgrid.cpp
  pivottable.cpp
  querytable.cpp
  reporttable.cpp
  kbalanceaxis.cpp
)

kde4_add_library(reports STATIC ${libreports_a_SOURCES})

add_dependencies(reports kmm_config)

############## tests ####################
if( KDE4_BUILD_TESTS )

  # Pivot Grid
  set( pivotgridtest_SRCS pivotgridtest.cpp reportstestcommon.cpp )

  kde4_add_unit_test( pivotgridtest TESTNAME kmymoney-pivotgridtest ${pivotgridtest_SRCS} )
  add_dependencies( pivotgridtest reports kmymoney_base kmymoney_common kmm_storage )

  target_link_libraries( pivotgridtest reports kmymoney_base kmymoney_common kmm_storage ${KDE4_KDEUI_LIBS} ${KDE4_KDECORE_LIBS} ${QT_QTGUI_LIBRARY} ${QT_QTXML_LIBRARY} ${QT_QTCORE_LIBRARY} ${QT_QTTEST_LIBRARY} )

  # Pivot Table
  set( pivottabletest_SRCS pivottabletest.cpp reportstestcommon.cpp ../mymoney/mymoneytestutils.cpp )

  kde4_add_unit_test( pivottabletest TESTNAME kmymoney-pivottabletest ${pivottabletest_SRCS} )

  add_dependencies( pivottabletest dialogs widgets reports settings kmymoney_base kmymoney_common kmm_kdchart kmm_storage kmm_config )

  target_link_libraries( pivottabletest reports settings kmymoney_base kmymoney_common dialogs widgets kmm_kdchart kmm_storage kmm_config ${KDE4_KDEUI_LIBS} ${KDE4_KDECORE_LIBS}  ${QT_QTGUI_LIBRARY} ${QT_QTXML_LIBRARY} ${QT_QTCORE_LIBRARY} ${QT_QTTEST_LIBRARY} )

  # Query Table
  set( querytabletest_SRCS querytabletest.cpp reportstestcommon.cpp ../mymoney/mymoneytestutils.cpp )

  kde4_add_unit_test( querytabletest TESTNAME kmymoney-querytabletest ${querytabletest_SRCS} )
  add_dependencies( querytabletest dialogs widgets reports settings kmymoney_base kmymoney_common kmm_storage kmm_config )

  target_link_libraries( querytabletest reports kmymoney_base kmymoney_common dialogs widgets kmm_storage kmm_config ${KDE4_KDEUI_LIBS} ${KDE4_KDECORE_LIBS} ${QT_QTGUI_LIBRARY} ${QT_QTXML_LIBRARY} ${QT_QTCORE_LIBRARY} ${QT_QTTEST_LIBRARY} )

endif( KDE4_BUILD_TESTS )
