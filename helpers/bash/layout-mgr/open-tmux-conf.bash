#!/bin/bash
# Used to open bash conf

tmux new-window -n 'tmux-conf' 'sudo nvim /etc/tmux.conf' \; split-window -h "tmux list-keys | nvim -R" \; select-pane -L 

# tmux list-keys
# tmux select-pane -L 

