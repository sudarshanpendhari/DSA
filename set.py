# Creating a set A
a=set()
m=int(input("Enter number of elements you want : "))

for i in range(m):
    obj1=int(input("Enter the elements : "))
    a.add(obj1)
print("Set A : ",a)

#Creating a set B
b=set()
n=int(input("Enter number of elements you want : "))

for i in range(n):
    obj2=int(input("Enter the elements : "))
    b.add(obj2)
print("Set B : ",b)


while True:
    print("\n================================================================")
    print("\n---------MENU---------")
    print("1.Add set")
    print("2.Remove set")
    print("3.Contain set")
    print("4.Intersection of Set A and B")
    print("5.Union of Set A and B")
    print("6.Difference Set A - Set B")
    print("7.Subset of Set")
    print("8.Exit")
    
    choice=int(input("\nEnter choice : "))
    
    if choice==1:
        
        ele1=int(input("\nEnter the element you want to add : "))
        a.add(ele1)
        print("\nAdd set A : ",a)
        
    elif choice == 2:
        ele2 = int(input("\nEnter the element you want to remove : "))
        
        if ele2 in a:
            a.remove(ele2)
            print("\nRemove set A : ", a)
        else:
            print("\nElement is not found in set A")
            
    elif choice == 3:
        
        key=input("\nEnter the element you want to search : ")
        
        for i in range(m):
            if key in a:
                print("\nTrue")
                break
            else:
                print("\nFalse")
        
    elif choice == 4:
        
        intersection=set()
        
        for key in a:
            if key in b:
                intersection.add(key)
                flag=0
                
            else:
                flag=1
                
        if(flag==1):
            print("\nNo common element")
            
        print("\nIntersection of set A and set B : ",intersection)
        
    elif choice == 5:
        
        union=set()
        
        for key in a:
            union.add(key)
            
        for key in b:
            union.add(key)
            
        print("\nUnion of A and B : ",union)
        
    elif choice == 6:
        
        Difference=set()
        
        for key in a:
            Difference.add(key)
            
        for key in intersection:
            Difference.remove(key)
            
        print("\nDifference Set A - Set B : ",Difference)
        
    elif choice == 7:
        
        subset=set()
        
        for key in b:
            if key in a:
                subset.add(key)
                if(subset==b):
                    print("B is subset of A")
                    
            else:
                print("\nSubset is not found") 
                
    elif choice == 8:
        break
    else:
        print("\nInvalid")