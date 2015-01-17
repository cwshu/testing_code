#!/usr/bin/python3

DESCRITION="""install configuration file to user environment"""
# ARGS HELP
GENERAL_HELP = 'install general rcfiles'
FISH_HELP = 'install fish config files (~/.config/fish)'

import sys
import argparse

def general_install():
    print('install general rcfiles')

def fish_install():
    print('install fish config files (~/.config/fish)')

def main():
    args_parser = argparse.ArgumentParser(description=DESCRITION)
    args_parser.add_argument('-g', '--general', action='store_true', help=GENERAL_HELP)
    args_parser.add_argument('--fish', action='store_true', help=FISH_HELP)
    args_parser.set_defaults(general=True)

    if len(sys.argv) == 1:
        # no arguments
        args_parser.print_help()

    args = args_parser.parse_args()

    print("\n** Installation Message start **")
    if args.general:
        general_install()
    
    if args.fish:
        fish_install()

    print("** Installation Message end **")

if __name__ == '__main__':
    main()
