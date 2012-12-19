# /*
#	This file is part of xtr.
#
#    xtr is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    xtr is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with xtr.  If not, see <http://www.gnu.org/licenses/>.
#
# */

BINPATH := /usr/local/bin

all: xtr

xtr: xtr.c 
	@echo 'Building target: $@'
	gcc -o "$@"  "xtr.c" -O2 -march=native -mtune=generic -fomit-frame-pointer -pipe
	@echo 'Finished building target: $@'
	@echo ' '

install:
	@install -m 'ug+rwx,o+rx' -vt "${BINPATH}" xtr

clean:
	@rm -v xtr;

