---
title: Terminal applications
author: Aleksandra
theme:
  name: catppuccin-mocha
---

Intro
---

- I have always preferred working in the terminal, it feels like you have
  everything in one place.
- WSL makes us even more terminal dependent than we would have been in Linux

<!-- end_slide -->

System utilities (1)
---

## starship

> Cool prompt, easily customizable

https://github.com/starship/starship

<!-- pause -->

## zoxide

> A smarter `cd` command

https://github.com/ajeetdsouza/zoxide

<!-- pause -->

## lsd / exa

> Better `ls` commands. Colours and icons out of the boxs, better defaults

https://github.com/lsd-rs/lsd

https://github.com/ogham/exa

<!-- end_slide -->

System utilities (2)
---

## fd

> A user-friendly alternative to `find`

https://github.com/sharkdp/fd

<!-- pause -->

## ripgrep

> Recursively search files for regex pattern, `find` + `grep`

https://github.com/BurntSushi/ripgrep

<!-- pause -->

## repgrep

> An interactive replacer for `ripgrep`, `find` + `sed`

https://github.com/acheronfail/repgrep

<!-- pause -->

## bat & tailspin

> `bat` is prettier output than `cat`
> `tailspin` is a log file highlighter

https://github.com/sharkdp/bat

https://github.com/bensadeh/tailspin

<!-- end_slide -->

System utilities (3)
---

## btop

> Resource monitor and `top` replacement

https://github.com/aristocratos/btop

<!-- pause -->

## rip

> Fuzzy find and kill processes

https://github.com/cesarferreira/rip

<!-- pause -->

## dua / dust

> View disk space usage and delete unwanted file, better `du`

https://github.com/Byron/dua-cli

https://github.com/bootandy/dust

<!-- end_slide -->

System utilities (4)
---

## atuin

> Shell history in db and optional sync

https://github.com/atuinsh/atuin

<!-- pause -->

## tokei

> Count lines of code in your project they way to actually mean

https://github.com/XAMPPRocky/tokei

<!-- pause -->

## zellij

> A modern multiplexer, replaces `screen` / `tmux`

https://github.com/zellij-org/zellij

<!-- end_slide -->

System utilities (5)
---

## tldr

> How you actually wished `man` worked 90% of the time

https://github.com/tealdeer-rs/tealdeer

<!-- pause -->

## dtrx

> Short for **do the right extraction**

https://github.com/brettcs/dtrx

<!-- pause -->

## clac

> A stack-based calculator

https://github.com/soveran/clac

<!-- pause -->

## clock-tui

> A simple clock / timer / stopwatch for the terminal

https://github.com/race604/clock-tui

<!-- end_slide -->

Development tools (1)
---

## lazygit & tig

> Simple (but powerful) TUI for git

https://github.com/jesseduffield/lazygit

https://github.com/jonas/tig

<!-- pause -->

## ducker / lazydocker

> Terminal apps for managing docker containers

https://github.com/robertpsoane/ducker

https://github.com/jesseduffield/lazydocker

<!-- pause -->

## httpie / xh & atac

> User-friendly tools for sending HTTP requests from the terminal

https://github.com/ducaale/xh

https://github.com/Julien-cpsn/ATAC

<!-- end_slide -->

Development tools (2)
---

## rainfrog

> A terminal database tool

https://github.com/achristmascarl/rainfrog

<!-- pause -->

## glim

> A TUI for monitoring GitLab CI pipelines

https://github.com/junkdog/glim

<!-- end_slide -->

Multi-media
---

## presenterm

> Markdown presentation framework, what I am using now

https://github.com/mfontanini/presenterm

<!-- pause -->

## freeze

> A tool to generate images of code and terminal output

https://github.com/charmbracelet/freeze

<!-- pause -->

## vhs

> Record videos of the terminal and save it as gifs

https://github.com/charmbracelet/vhs

<!-- end_slide -->

Dotfile and system management
---

I use <span style="color: p:mauve">ansible</span> for dotfile and system management. 

- Each system is defined by a _playbook_ and _variables_
- Have branching paths depending on e.g. which package manager I use
- Can optionally install applications for first-time setup
- Differing config files use jinja templates

<!-- end_slide -->

For fun
---

## thefuck

> Corrects incorrect or misspelled console commands

https://github.com/nvbn/thefuck

<!-- pause -->

## plastic

> A NES emulator in the terminal

https://github.com/Amjad50/plastic
