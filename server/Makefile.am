AUTOMAKE_OPTIONS = subdir-objects 
ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS}
AM_CPPFLAGS = ${DOB_SERVER_CFLAGS}
bin_PROGRAMS = dob_server
dob_server_SOURCES = src/server.cc \
		     src/user.cc \
		     src/database.cc \
		     src/main.cc

dob_server_LDADD = ${DOB_SERVER_LIBS}
#SUBDIRS = src

#dist_noins_SCRIPTS = any_script.sh
