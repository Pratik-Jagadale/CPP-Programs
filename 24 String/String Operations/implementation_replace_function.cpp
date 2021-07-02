class cpa_string
{
	private:
	   char* p;
	   size_t length;
	public:
	   void replace(int i, int j,const char* cp, size_t n)
	   {
	        int delta = n - (j - i + 1);
	        int new_str_length  = length + delta;
	        char* tmp_p = (char*)malloc(new_str_length + 1);
	        assert(tmp_p);
	        strncpy(tmp_p, p, i);
	        strncpy(tmp_p, cp, n);
	        strncpy(tmp_p, j, length - 1);
	        tmp_p[new_str_length - 1] = '\0';
	        free(p);
	        p = tmp_p;
	        length = new_str_length;
	   }
};

int main()
{
	cpa_string *ptr = new cpa_string();
    return 0;
}

