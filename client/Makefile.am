
AUTOMAKE_OPTIONS = subdir-objects 

ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS}

AM_CPPFLAGS = ${DOB_CFLAGS}

bin_PROGRAMS = dob

dob_SOURCES = src/main.cc \
			  src/win-main.cc \
			  src/dialog-preferences.cc \
			  src/dialog-new_user.cc \
			  src/config.cc \
			  src/client.cc 

dob_LDADD = ${DOB_LIBS}

#SUBDIRS = src

#dist_noins_SCRIPTS = any_script.sh
