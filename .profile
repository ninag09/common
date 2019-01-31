export CLICOLOR=1
export LSCOLORS=ExfxbxdxCxegedabagacad
#\e[1;31m indicates Red color and Boldness
#Black        0;30     Dark Gray     1;30
#Red          0;31     Light Red     1;31
#Green        0;32     Light Green   1;32
#Brown/Orange 0;33     Yellow        1;33
#Blue         0;34     Light Blue    1;34
#Purple       0;35     Light Purple  1;35
#Cyan         0;36     Light Cyan    1;36
#Light Gray   0;37     White         1;37
#\u @ \h \W indicates the format of the prompt: user@host path.
#\e[0m indicates format text reset
#export PS1='\[\e[0;33m\]\u\[\e[0m\]@\[\e[0;32m\]\h\[\e[0m\]:\[\e[0;34m\]\w\[\e[0m\]\$ '
export PS1='\[\e[0;32m\]Nithesh: \w\$ \[\e[0m\]' #Default
RED='\033[42;31m'
NC='\033[0m' # No Color

# basic
alias cp='cp -i'
alias mv='mv -i'
alias ...='cd -'
alias l='ls -F'
alias ll='ls -lrth'
alias l.='ls -all'
alias grep='grep -i --color'
alias grepl='grep -rl'
alias brc='vim /Users/Nithesh/.profile'
alias vimrc='vim /Users/Nithesh/.vimrc'
alias src='source /Users/Nithesh/.profile'
alias histgrep='history | grep'
alias vimcmds='vim /Users/Nithesh/.commands'
alias cmds='cat /Users/Nithesh/.commands'
alias vimcommon='vim /Users/Nithesh/test/headers/common.h'
alias inputs='vim /Users/Nithesh/test/input.txt'
alias showlog='vim /Users/Nithesh/test/Log.txt'
alias clearlog='> /Users/Nithesh/test/Log.txt'

alias headers='cd /Users/Nithesh/test/headers'

#functions
# grep bashrc file
function greprc {
    if [ -z "$1" ]; then
        echo "Usage: greprc 'value'"
        return 1
    else
        grep $1 '/Users/Nithesh/.profile'
    fi
}

# cd one level up and change
function .. {
   if [ -z "$1" ]; then
       cd ".."
   else
       cd "../""$1"
   fi
}

# change test directories
function test {
    if [ -z "$1" ]; then
        echo -e "${RED}* User Commands *${NC}"
        cmds
        cd '/Users/Nithesh/test/'
        echo -e "${RED}* Available directories *${NC}"
        l '/Users/Nithesh/test' | grep \/
        return 1
    else
        cd '/Users/Nithesh/test/'"$1"
    fi
    if [ $? -ne 0 ]; then
        echo "* Available directories *"
        ls '/Users/Nithesh/test' | grep \/
    fi
}

#  create directory and cd to it
function mcd {
    if [ -z "$1" ]; then
        echo "Usage: mcd 'folder name'"
        return 1
    else
        mkdir -pv "$1"
        cd "$1"
    fi
}

# open assignments folder
function assig {
    cd '/Users/Nithesh/Documents/Assignments/'
    open '/Users/Nithesh/Documents/Assignments/'
}

#compile c files
function c {
    if [ -z "$1" ]; then
        echo "Enter .c file"
    else
        gcc -I/Users/Nithesh/test/headers/ $1
    fi
}

#complie and generate
function cplus {
    if [ -z "$1" ]; then
        echo "Enter .cpp file"
    else
        cmd=`echo $1 | awk -F "." '{print $1}'`
        g++ -std=c++14 -I$HOME/test/headers/ $2 $1 -o $cmd
    fi
}

#complie and generate
function cplusasm {
    if [ -z "$1" ]; then
        echo "Enter .cpp file"
    else
        cmd=`echo $1 | awk -F "." '{print $1}'`
        g++ -std=c++14 -I$HOME/test/headers/ $2 -S -o $cmd.s $1
    fi
}

#complie and generate
function cplusdebug {
    if [ -z "$1" ]; then
        echo "Enter .cpp file"
    else
        cmd=`echo $1 | awk -F "." '{print $1}'`
        g++ -std=c++14 -I$HOME/test/headers/ $2 -g $1 -o $cmd
    fi
}

function warcplus {
    if [ -z "$1" ]; then
        echo "Enter .cpp file"
    else
        cmd=`echo $1 | awk -F "." '{print $1}'`
        g++ -Wall -std=c++14 -I$HOME/test/headers/ $1 -o $cmd
    fi
}

#execute and remove C++ object file
function xx {
    if [ -z "$1" ]; then
        echo "Enter filename"
    else
        cmd=`echo $1 | awk -F "." '{print $1}'`
        ./$cmd
        rm $cmd
    fi
}

#execute
function r {
    if [ -z "$1" ]; then
        echo "Enter filename"
    else
        cmd=`echo $1 | awk -F "." '{print $1}'`
        ./$cmd
    fi
}

#find file from current path
function findfile {
    find . -name $1    
}

# up N: moves N times upwards (cd ../../../{N})
function up {
    LIMIT=$1
    P="$PWD"
    for ((i=1; i <= LIMIT; i++))
    do
        P="$P"/..
    done
    cd "$P"
    echo $PWD
}

# Create save path file if it is not created
if [ ! -e ~/.sp ] ; then
    touch ~/.sp
fi

#save path: save the current path to a hidden file
function tp {
    pwd > ~/.sp
}
#goto saved path: goes where the previously saved tp points
function gtp {
    cd "`cat ~/.sp`"
}

function taillog {
    > $HOME/test/Log.txt
    tail -f $HOME/test/Log.txt
}

# Setting PATH for Python 3.6
# The original version is saved in .profile.pysave
PATH="/Library/Frameworks/Python.framework/Versions/3.6/bin:${PATH}"
export PATH
