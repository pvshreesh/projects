import tkinter
input_list = []
def buttonClicked(data):
    str1 = data.get()
    print(str1)
    l1 = [i for i in str1.split(",")]
    l2=[]
    for i in l1:
        if i == '':
            l2.append(0)
        else:
            l2.append(int(i))
    global input_list
    input_list = l2.copy()
    print(input_list)
    print()
    print()
    root.destroy()

root = tkinter.Tk()
root.geometry('400x250')
prompt = tkinter.Label(root, text = "Enter Number of Soldiers for each color")
prompt2 = tkinter.Label(root, text = "Enter Comma seperated values, For example: '1,2,4,3'")
data = tkinter.Entry(root)
but = tkinter.Button(root, text ="Solve!", command =lambda: buttonClicked(data))

prompt.grid(row=0)
prompt2.grid(row=1)
data.grid(row=2)
tkinter.Label(root, text="").grid(row=3)
but.grid(row=4)
tkinter.mainloop()

# GUI part is done


last=[]
b=[-1,-1]
rr=[1]


def good_state(li,n):       #final state
    sum=0
    for i in range(n):
        if li[i]==0:
            sum=sum+1
    if sum==n:
        return 1
    else:
        return 0

def check_state(li,n):       #wrong state or not
    wrong=0
    for i in range(n):
        if li[i]<=0:
            wrong=wrong+1
            
    if wrong>=n-1:
        return 0
    if wrong<n-1:
        return 1

def solve(l,r,n,rr):
    
    if good_state(l,n)==1:
        print('yes')
    if(check_state(l,n)==0):
        rr[0]=rr[0]-1
        x=last.pop(-1)
        l[x]=l[x]+1
        r[x]=r[x]-1
        #print('')
        print('      *****  Back Tracked ******')
        
        
    else:
        for n1 in range(0,n):
            for n2 in range(0,n):
                if n1!=n2 and l[n1]!=0 and l[n2]!=0:
                    l[n1]=l[n1]-1
                    l[n2]=l[n2]-1
                    last.append(n1)
                    b[0]=chr(65+n1)
                    b[1]=chr(65+n2)
                    if rr[0]<10:
                        print('0'+str(rr[0]),'   |  ',l,'|  ->>',b,' ->>  |',r)
                    else:
                        print(str(rr[0]),'   |  ',l,'|  ->>',b,' ->>  |',r)
                    r[n1]=r[n1]+1
                    r[n2]=r[n2]+1
                    
                    if good_state(l,n)==1:
                        print('')
                        print('Succefully Moved All Soldiers!')
                        
                    else:
                        r[n2]=r[n2]-1
                        b[0]=chr(65+n2)
                        b[1]=' '
                        print('      |  ',l,'|  <<-',b,' <<-  |',r)
                        l[n2]=l[n2]+1
                        print('')
                        rr[0]=rr[0]+1
                        solve(l,r,n,rr)
#l=[3,2,1]
l = input_list
n=len(l)
r=[]
for i in range(n):
    r.append(0)
    
b=[-1,-1]
sum=0
for i in range(n):
    if l[i]==0:
        sum=sum+1
if sum>=n-1:
    print('****wrong inputs*******')
else:
    print("Soldiers in index 0 are of color 'A', index 1 are of 'B' and so on...")
    print()
    print()
    print('steps |   Left coast',end='')
    for i in range(n-3):
        print('   ',end='')
    print('|      Boat             | Right coast')
    print('------+-------------',end='')
    for i in range(n-3):
        print('---',end='')
    print('+-----------------------+--------------------')
    print(' ')
    solve(l,r,n,rr)
    print()
    print("Final Values: ")
    print("Left Coast = ", l)
    print("Right Coast = ",r)
    print()
    print(str(rr[0])+' steps taken')
    print()
