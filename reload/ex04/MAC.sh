#!/bin/bash

ifconfig -a | grep ether | cut -c8- | tr -d ' '
