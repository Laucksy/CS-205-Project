import java.util.*;
/**
 * Write a description of class BinaryTree here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class BinaryTree<K extends Number & Comparable <K>, E>
{
    int size;
    BinaryTreeNode<E> root;
    boolean removed;
    /**
     * Constructor for objects of class BinaryTree
     */
    public BinaryTree()
    {
        size=0;
    }

    public void add(K value,E thing)
    {
        if(size==0)
        {

            BinaryTreeNode<E> first = new BinaryTreeNode<E>(value,thing);
            root=first;
            size++;
        }
        else
        {
            Boolean notEnd = true;
            BinaryTreeNode<E> temp = root;
            while(temp.getKey().compareTo(value)!=0 && notEnd)
            {
                if(temp.getKey().compareTo(value)<0)
                {
                    if(temp.bigSide==null)
                    {
                        BinaryTreeNode<E> newThing = new BinaryTreeNode<E>(value,thing);
                        temp.bigSide=newThing;
                        notEnd=false;
                        size++;
                    }
                    else
                    {                      
                        temp=temp.bigSide;
                    }
                }
                else if (temp.getKey().compareTo(value)>0)
                {
                    if(temp.smallSide==null)
                    {
                        BinaryTreeNode<E> newThing = new BinaryTreeNode<E>(value,thing);
                        temp.smallSide=newThing;
                        notEnd=false;
                        size++;
                    }
                    else
                    {   
                        temp=temp.smallSide;
                    }
                }
            }
            if(temp.getKey().compareTo(value)==0)
            {
                temp.add(thing);
            }
        }
    }

    public boolean contains(K k)
    {
        BinaryTreeNode<E> temp = root;
        if(size==0)
        {
            return false;
        }
        else
        {
            while(temp.getKey().compareTo(k)!=0)
            {

                if(temp.getKey().compareTo(k)<0)
                {
                    if(temp.bigSide!=null)
                    {
                        temp=temp.bigSide;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if(temp.getKey().compareTo(k)>0)
                {
                    if(temp.smallSide!=null)
                    {
                        temp=temp.smallSide;
                    }
                    else
                    {
                        return false;
                    }
                }         
            }
            return true;
        }
    }

    public ArrayList<E> first() 
    {
        BinaryTreeNode<E> temp = root;
        while(temp.smallSide!=null)
        {
            temp=temp.smallSide;
        }
        return temp.getElementList();
    }

    public boolean remove(K k)
    {

        root= remove(k,root);
        if(removed)
        {
            size--;
        }
        return removed;

    }

    public BinaryTreeNode<E> remove(K k,BinaryTreeNode<E> r)
    {
        BinaryTreeNode<E> temp = r;
        if(temp==null)
        {
            removed = false;
        }
        else
        {
            removed = true;
            if(k.compareTo(temp.getKey())<0)
            {
                temp.smallSide=remove(k,temp.smallSide);
            }
            else if(k.compareTo(temp.getKey())>0)
            {
                temp.bigSide=remove(k,temp.bigSide);
            }
            else if( temp.smallSide!=null &&  temp.bigSide != null) // 2 children
            {
                temp.element = findMin(temp.bigSide).element;
                temp.bigSide= removeMin(temp.bigSide);
            }
            else
            {
                r= (temp.bigSide!= null) ? temp.smallSide : temp.bigSide;
            }

        }
        return r;
    }

    protected BinaryTreeNode<E> findMin(BinaryTreeNode<E> r)
    {
        if(r!= null)
        {
            while(r.smallSide!= null)
            {
                r=r.smallSide;
            }
        }
        return r;
    }

    protected BinaryTreeNode<E> removeMin(BinaryTreeNode<E> r)
    {
        if(r== null)
        {
            return null;
        }
        else if(r.smallSide!= null)
        {
            r.smallSide=removeMin(r.smallSide);
            return r;
        }
        else
        {
            return r.bigSide;
        }

    }
    void inOrder ()
    {
     inOrder (root);   
    }

    void inOrder (BinaryTreeNode<E> r)
    {

        if(r == null) {
            return;
        }

        inOrder( r.smallSide );

        System.out.println(root.getKey());

        inOrder( r.bigSide ); 

    }

    public class BinaryTreeNode<E>
    {
        private K key;
        protected ArrayList<E> element ;
        protected BinaryTreeNode<E> smallSide;
        protected BinaryTreeNode<E> bigSide;
        public BinaryTreeNode(K k, E e)
        {
            key=k;
            element = new ArrayList<E>();
            element.add(e);

        }

        public K getKey()
        {
            return key;
        }

        public void add(E temp)
        {
            element.add(temp);
        }

        public ArrayList<E> getElementList()
        {
            return element; 
        }

    }
}

