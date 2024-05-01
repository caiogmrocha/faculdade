gcc bstavl.c main.c -o main -g -Wall -Werror

# create an loop to test the output of the program in directory ./tests

while :
do
    for file in ./tests/*; do
        if [ -f "$file" ]; then
            if [[ $file != *.out.txt ]]; then
                filename=$(basename -- "$file")
                filename="${filename%.*}"
                filename="${filename%.*}"

                ./main < ./tests/$filename.in.txt > ./tests/$filename.in.out.txt

                if diff ./tests/$filename.out.txt ./tests/$filename.in.out.txt; then
                    echo "✅ $filename"
                else
                    echo "❌ $filename"
                fi
            fi
        fi
    done

    sleep .5

    clear
done