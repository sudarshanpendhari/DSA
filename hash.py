Ht=[[] for _ in range(10)]
print(Ht)
def insert(Ht,key,value):
    hpos=hash(key)%10
    print(hpos)
    bucket=Ht[hpos]
    duplicate=False
    for kv in enumerate(bucket):
        k,v=kv
       
        if(k==key):
            duplicate=True
            break;
        else:
            duplicate=False
    if(duplicate==False):
        bucket.append((key,value))
        print(bucket)
        print(Ht)
    else:
        print("record key already present,cant add")
"""insert(Ht,10,"100")
insert(Ht,50,"ksa")
insert(Ht,10,"sjk")"""
def find(Ht,key):
    bucket=Ht[hash(key)%10]
    for i,kv in enumerate(bucket):
        k,v=kv
       
        if(k==key):
            flag=1
            break;
        else:
            flag=0
    if(flag==1):
        print(kv)
    else:
        print("not found")
            
#find(Ht,50)   
def delete(Ht,key):
    bucket=Ht[hash(key)%10]
    for i,kv in enumerate(bucket):
        k,v=kv
       
        if(k==key):
            bucket.remove(kv)
            break;
    print(Ht)        
#delete(Ht,50)     
while(True):

	print("#########################################Menu#############################\n1.Insert\n2.delete\n3.find\n0.Exit")
	ch=int(input())
	
	if(ch==0):
		exit()
	elif(ch==1):
		key=int(input("Enter key"))
		value=input("Enter value")
		insert(Ht,key,value)
	elif(ch==2):
		key=int(input("Enter key"))
		delete(Ht,key)
	elif(ch==3):
		key=int(input("Enter key"))
		find(Ht,key)
	else:
	    print("")	
	




