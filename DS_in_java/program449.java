// Doubly Circular.. completed.

class node
{
    public int data;
    public node next;
    public node prev;

    public node(int no)
    {
        this.data = no;
        this.next = null;
        this.prev = null;
    }
}

class DoublyCL
{
    private node first;
    private node last;
    private int iCount;

    public DoublyCL()
    {
        System.out.println("Object of DoublyCL gets created");
        this.first = null;
        this.last = null;

        this.iCount = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = null;

        newn = new node(no);
        
        if((this.first == null) && (this.last == null))
        {
            this.first = newn;
            this.last = this.first;
        }
        else
        {
            newn.next = this.first;
            this.first.prev = newn;
            this.first = newn;
        }
        this.last.next = this.first;
        this.first.prev = this.last;
         
        this.iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = null;

        newn = new node(no);
        
        if((this.first == null) && (this.last == null))
        {
            this.first = newn;
            this.last = this.first;
        }
        else
        {
            this.last.next = newn;
            newn.prev = this.last;
            this.last = newn;
        }
        this.last.next = this.first;
        this.first.prev = this.last;
         
        this.iCount++;
    }

    public void DeleteFirst()
    {
        if((this.first == null) && (this.last == null))
        {
            return;
        }
        else if(this.first == this.last)
        {
            this.first = null;
            this.last = null;
        }
        else 
        {   
            this.first = this.first.next;

            this.last.next = this.first;
            this.first.prev = this.last;
        }
        System.gc();
        this.iCount--;
    }

    public void DeleteLast()
    {
        if((this.first == null) && (this.last == null))
        {
            return;
        }
        else if(this.first == this.last)
        {
            this.first = null;
            this.last = null;
        }
        else 
        {   
            this.last = this.last.prev;
            this.last.next = this.first;
            this.first.prev = this.last;
        }
        System.gc();
        this.iCount--;
    }

    public void Display()
    {
        node temp = null;

        temp = this.first;
        do
        {
            System.out.print("|"+temp.data+" | <=> ");
            temp = temp.next;
        }while(temp != this.last.next);

        System.out.println("");
    }

    public int Count()
    {
        return this.iCount;
    }

    public void InsertAtPos(int no,int pos)
    {
        node newn = null;
        node temp = null;
        int iCnt = 0;

        if(pos < 1 || pos > iCount+1)
        {
            System.out.println("Invalid Position");
            return;
        }

        if(pos == 1)
        {
            this.InsertFirst(no);
        }
        else if (pos == iCount + 1)
        {
            this.InsertLast(no);
        }
        else 
        {
            newn = new node(no);
            temp = this.first;

            for(iCnt = 1; iCnt < pos-1; iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            newn.next.prev = newn;

            temp.next = newn;
            newn.prev = temp;

            this.iCount++;
        }

    }

    public void DeleteAtPos(int pos)
    {
        node temp = null;
        int iCnt = 0;

        if(pos < 1 || pos > iCount)
        {
            System.out.println("Invalid Position");
            return;
        }

        if(pos == 1)
        {
            this.DeleteFirst();
        }
        else if(pos == iCount)
        {
            this.DeleteLast();
        }
        else 
        {
            temp = first;
            for(iCnt = 1; iCnt < pos-1; iCnt++)
            {
                temp = temp.next;
            }
            temp.next = temp.next.next;
            
            temp.next.prev = temp;

            this.iCount--;
        }
    }
}

class program449
{
    public static void main(String args[])
    {
       DoublyCL obj = null;
        int iRet = 0;

        obj = new DoublyCL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes are :" +iRet);

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);
         obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes are :" +iRet);

        obj.DeleteFirst();
        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes are :" +iRet);

        obj.DeleteLast();
        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes are :" +iRet);

        obj.InsertAtPos(105, 4);
        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes are :" +iRet);

        obj.DeleteAtPos(4);
        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes are :" +iRet);



        // IMPORTANT for MEMORY DEALLOCATION...
        obj = null;
        System.gc();
    }
}
