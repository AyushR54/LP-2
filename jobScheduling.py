profit=[]
n=int(input("Enter the no.of element: "))
for i in range(n):
    m=int(input("ENter the profit: "))
    profit.append(m)

jobs=[]
for i in range(n):
    b=str(input("ENter the Jobs: "))
    jobs.append(b)

deadline=[]
for i in range(n):
    c=int(input("ENter the deadline: "))
    deadline.append(c)

profitNJobs=list(zip(profit,jobs,deadline))
profitNJobs=sorted(profitNJobs,key=lambda x:x[0],reverse=True)
slot=[]
for _ in range(len(jobs)):
    slot.append(0)

profit=0
ans=[]

for i in range(len(jobs)):
    ans.append('null')

for i in range (len(jobs)):
    job=profitNJobs[i]
    #check slot occupied
    for j in range (job[2],0,-1):
        if slot[j]==0:
            ans[j]=job[1]
            profit+=job[0]
            slot[j]=1
            break
print("Jobs scheduled Buddy : ",ans[1:])
print("Profit ",profit)