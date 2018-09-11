array = raw_input()
array = array.split()
map(lambda x:int(x)%5==0,array)

