build:
	gcc crypto.c -o crypto
	gcc stocks.c -o stocks
	gcc valley.c -o valley
	gcc ridge.c -o ridge

run-p1:
	./crypto

run-p2:
	./stocks

run-p3:
	./valley

run-p4:      # nume necesar 
	./ridge

clean:
	rm crypto
	rm stocks
	rm valley
	rm ridge