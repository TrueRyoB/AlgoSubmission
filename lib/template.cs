using System;
using System.IO;
using System.Text;
using System.Collections.Generic;

var fs = new FastScanner();
var sb = new StringBuilder();





Console.Write(sb.ToString());

class Nms
{
  public static T[] Array<T>(int n, Func<T> f)
  {
    var a = new T[n];
    for(int i=0;i<n;i++) a[i]=f();
    return a;
  }
  public static T[] Array<T>(int n, T val)
  {
    var a = new T[n];
    for(int i=0;i<n;i++) a[i]=val;
    return a;
  }
}

class Graph
{
  public static readonly int[] D = [-1, 0, 1, 0, -1, -1, 1, 1, -1];
  public const int TRUE = 1;
  public const int FALSE = 0;
  public static long MinPositive(long a, long b)
  {
    return (a<0 || b<0) ? Math.Max(a, b) : Math.Min(a, b);
  }
}

class Sugaku
{
  public const long MOD7 = 1000000007L;
  public const long MOD3 = 998344353L;
  public const int INF = 1001001001;
  public const long LINF = 1001001001001001001L;

  public static long ModPow(long b, long r, long MOD)
  {
    long res=1;
    while(r>0)
    {
      if((r&1)!=0) res = res*b%MOD;
      b=b*b%MOD;
      r>>=1;
    }
    return res;
  }

  public static bool ChMax<T>(ref T a, T b) where T: IComparable<T>
  {
    if(a.CompareTo(b)<0)
    {
      a=b;
      return true;
    }
    return false;
  }
  public static bool ChMin<T>(ref T a, T b) where T: IComparable<T>
  {
    if(a.CompareTo(b)>0)
    {
      a=b;
      return true;
    }
    return false;
  }
}

class FastScanner
{
  private readonly Stream stream = Console.OpenStandardInput();
  private readonly byte[] buffer = new byte[1 << 16];
  private int ptr = 0, len = 0;

  private byte Read()
  {
    if (ptr >= len)
    {
      len = stream.Read(buffer, 0, buffer.Length);
      ptr = 0;
      if (len == 0) return 0;
    }
    return buffer[ptr++];
  }

  public int Int()
  {
    int c;
    while ((c = Read()) <= ' ') if (c == 0) return 0;
    int sign = 1;
    if (c == '-')
    {
      sign = -1;
      c = Read();
    }
    int val = c - '0';
    while ((c = Read()) >= '0')
      val = val * 10 + c - '0';
    return val * sign;
  }

  public long Long()
  {
    int c;
    while ((c = Read()) <= ' ') if (c == 0) return 0;
    int sign = 1;
    if (c == '-')
    {
      sign = -1;
      c = Read();
    }
    long val = c - '0';
    while ((c = Read()) >= '0')
      val = val * 10 + c - '0';
    return val * sign;
  }

  public string String()
  {
    int c;
    while ((c = Read()) <= ' ') if (c == 0) return "";
    var sb = new StringBuilder();
    do
    {
      sb.Append((char)c);
      c = Read();
    } while (c > ' ');
    return sb.ToString();
  }
}