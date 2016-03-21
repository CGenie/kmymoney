# patch the version with the version defined in the build system
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/kmm_lua.desktop
  ${CMAKE_CURRENT_BINARY_DIR}/kmm_lua.desktop
)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}
                    ${CMAKE_CURRENT_BINARY_DIR})

########### next target ###############

SET(kmm_lua_PART_SRCS
  luaplugin.cpp
)

KDE4_ADD_UI_FILES(kmm_lua_PART_SRCS
  lua.ui
)

KDE4_ADD_PLUGIN(kmm_lua
  ${kmm_lua_PART_SRCS}
)

TARGET_LINK_LIBRARIES(kmm_lua
  kmm_mymoney kmm_plugin
  ${KDE4_KDEUI_LIBS} ${KDE4_KIO_LIBS}
  ${GMP_LIBRARIES}
  ${LIBALKIMIA_LIBRARY}
)

#IF(KDE4_BUILD_TESTS)
#  SET(csvdatetest_SRCS csvdatetest.cpp convdate.cpp)
#  KDE4_ADD_UNIT_TEST(csvdatetest TESTNAME kmymoney-plugin-csvdatetest
#    ${csvdatetest_SRCS})
#  TARGET_LINK_LIBRARIES(csvdatetest ${QT_AND_KDECORE_LIBS}
#    ${QT_QTTEST_LIBRARY} ${KDE4_KDECORE_LIBS} kmm_mymoney)
#
#  SET(parsedatatest_SRCS parsedatatest.cpp csvutil.cpp)
#  KDE4_ADD_UNIT_TEST(parsedatatest TESTNAME kmymoney-plugin-parsedatatest
#    ${parsedatatest_SRCS})
#  TARGET_LINK_LIBRARIES(parsedatatest ${QT_AND_KDECORE_LIBS} ${KDE4_KDEUI_LIBS}
#    ${QT_QTTEST_LIBRARY} ${KDE4_KDECORE_LIBS} ${GMP_LIBRARIES}
#    ${LIBALKIMIA_LIBRARY} kmm_mymoney)
#
#  SET(symboltest_SRCS symboltest.cpp csvutil.cpp)
#  KDE4_ADD_UNIT_TEST(symboltest TESTNAME kmymoney-plugin-symboltest
#    ${symboltest_SRCS})
#  TARGET_LINK_LIBRARIES(symboltest ${QT_AND_KDECORE_LIBS} ${KDE4_KDEUI_LIBS}
#    ${QT_QTTEST_LIBRARY} ${KDE4_KDECORE_LIBS} ${GMP_LIBRARIES}
#    ${LIBALKIMIA_LIBRARY} kmm_mymoney)
#ENDIF(KDE4_BUILD_TESTS)

########### install files ###############

INSTALL(FILES kmm_lua.rc
        DESTINATION  ${DATA_INSTALL_DIR}/kmm_lua)

INSTALL(TARGETS kmm_lua
        DESTINATION ${PLUGIN_INSTALL_DIR})

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/kmm_lua.desktop
        DESTINATION ${SERVICES_INSTALL_DIR})

INSTALL(FILES luarc
  DESTINATION ${CONFIG_INSTALL_DIR})
