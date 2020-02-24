 void* memccpy (void* restrict dst, const void* restrict src, int c, size_t n)
      {
        void *pc = memchr (src, c, n);
        void *ret;

        if (pc)
        {
          n = (char*)pc - (char*)src + 1;
          ret = (char*)dst + n;
        }
        else
          ret = 0;

        memcpy (dst, src, n);
        return ret;
      }
	  
	  
	  void* memccpy (void* restrict dst, const void* restrict src, int c, size_t n)
      {
        const char *s = src;
        for (char *ret = dst; n; ++ret, ++s, --n)
        {
          *ret = *s;
          if ((unsigned char)*ret == (unsigned char)c)
            return ret + 1;
        }
        return 0;
      }