using System;
using System.Runtime.CompilerServices;
using System.Text;

namespace Stack
{
    class StackFun
    {
        public static Stack<int> stack = new Stack<int>();
        public void Push(int x)
        {
            stack.Push(x);
        }
        public int Pop()
        {
            if (stack.Count == 0)
                return -1;
            else
                return stack.Pop();
        }
        public int Size()
        {
            return stack.Count();
        }
        public int Empty()
        {
            if (stack.Count > 0)
                return 0;
            else
                return 1;
        }
        public int Top()
        {
            if (stack.Count > 0)
                return stack.Peek();
            else
                return -1;
        }
    }

    class MyStack
    {
        static void Main()
        {
            int T = int.Parse(Console.ReadLine());
            StackFun stk = new StackFun();
            StringBuilder sb = new StringBuilder();

            for(int i = 0; i < T; i++)
            {
                string[] s = Console.ReadLine().Split();
                if (s[0] == "push")
                    stk.Push(int.Parse(s[1]));
                else if (s[0] == "pop")
                    sb.AppendLine(stk.Pop().ToString());
                else if (s[0] == "size")
                    sb.AppendLine(stk.Size().ToString());
                else if (s[0] == "empty")
                    sb.AppendLine(stk.Empty().ToString());
                else if (s[0] == "top")
                    sb.AppendLine(stk.Top().ToString());
                else
                    continue;
            }
            Console.WriteLine(sb.ToString());
        }       
    }
}
