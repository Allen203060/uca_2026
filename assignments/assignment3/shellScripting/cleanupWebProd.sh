#!/bin/bash

LOG_FILE="server-access.log"

sed -i -E 's/[0-9]{4}-?[0-9]{4}-?[0-9]{4}-?[0-9]{4}/XXXX-XXXX-XXXX-XXXX/g; s|HTTP/1\.0|HTTP/1.1|g; /^#/d' "$LOG_FILE" 