def factorial(value):
	print reduce(lambda x,y:x*y,range(1,value))

factorial(8)
