syntax on

"colorscheme summerfruit256

imap <c-d> <esc>ddi
nmap <c-d> dd

autocmd FileType python imap :<CR> :<CR><TAB>
autocmd BufRead *.c* set cindent

"comment and uncomment visualblock
autocmd FileType cpp,c vnoremap cc I//<esc>
autocmd FileType python vnoremap cc I#<esc>
autocmd FileType cpp,c vnoremap cu <right>x
onoremap p i(
onoremap P i{

"Trailing white spaces
let maplocalleader=','
nnoremap <buffer> <localleader>sw :call StripTrailingWhitespaces()<cr>
nnoremap <s-w> /\s\+$<cr>
nnoremap <localleader>n :setlocal number!<cr>

" General
set nonumber  " Show line numbers
set linebreak " Break lines at word (requires Wrap lines)
"set showbreak=+++ " Wrap-broken line prefix
"set textwidth=100 " Line wrap (number of cols)
set showmatch " Highlight matching brace
set wildmenu
set wildmode=longest:list,full
set visualbell  " Use visual bell (no beeping)
set t_vb=

set hlsearch  " Highlight all search results
set smartcase " Enable smart-case search
set ignorecase  " Always case-insensitive
set incsearch " Searches for strings incrementally

set autoindent  " Auto-indent new lines
set expandtab " Use spaces instead of tabs
set shiftwidth=4  " Number of auto-indent spaces
set smarttab  " Enable smart-tabs
set tabstop=4 " Number of spaces per Tab
set softtabstop=4 " Number of spaces per Tab

" Advanced
set ruler " Show row and column ruler information

set undolevels=1000 " Number of undo levels
set backspace=indent,eol,start  " Backspace behaviour

set showmode    "Show current mode down the bottom
set mouse=n
set tags=$HOME/test/tags
" strips trailing whitespace at the end of files. this
" is called on buffer write in the autogroup above.
function! StripTrailingWhitespaces()
    " save last search & cursor position
    let _s=@/
    let l = line(".")
    let c = col(".")
    %s/\s\+$//e
    let @/=_s
    call cursor(l, c)
endfunction

nnoremap <localleader>g :set operatorfunc=GrepOperator<cr>g@
vnoremap <localleader>g :<c-u>call GrepOperator(visualmode())<cr>

function! GrepOperator(type)
    if a:type ==# 'v'
        normal! `<v`>y
    elseif a:type ==# 'char'
        normal! `[v`]y
    else
        return
    endif

    silent execute "grep! -R " . shellescape(@@) . " ."
    copen
endfunction

" Stupid shift key fixes
cmap W w
cmap WQ wq
cmap wQ wq
cmap Q q
