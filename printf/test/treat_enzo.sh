rm -f treat_enzo.txt
gcc -Wall -Wextra main.c 2>&1 >/dev/null | grep "warning" | sed '$d' | cut -f 2 -d : | uniq > treat_enzo.txt
i=0
while read p; do
	let p=p-i
	sed -i '' "${p}d" "main.c"
	let i+=1
done < treat_enzo.txt
