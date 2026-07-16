awk -F: '!/^#/ && NR % 2 == 0 {print $1}' /etc/passwd \
  | sort -r -f \
  | awk -v FT_LINE1="$FT_LINE1" -v FT_LINE2="$FT_LINE2" 'NR >= FT_LINE1 && NR <= FT_LINE2' \
  | paste -sd ',' - | sed 's/,$/./'
