#include "StringTable.h"
/*
#include <hash_set>
#include <set>

inline size_t LuaClassStringHash(const Bucket& p)  {
	const char* str = p.str.c_str();
	size_t l = p.str.length();
	unsigned int h = (unsigned int)l; // seed
	size_t step = (h>>5)+1;  
	for (size_t l1=l; l1>=step; l1-=step) 
		h = h ^ ((h<<5)+(h>>2)+(unsigned char)(str[l1-1]));
  return h;
}
 struct Bucket { 
	 char* str; 
	 Bucket* next;
	 Bucket(const char* k) :  next(NULL) { 
			size_t l = strlen(k)+1;
			str = new char[l+1];
			memcpy(str,k,l);
			str[l] = NULL;
	 }
	 ~Bucket() {  if(str) delete str; }
	 inline bool operator==(const Bucket& r) { return r.str == str; }
 };




struct BucketEqual {
	inline bool operator()(const Bucket& l, const Bucket& r) const {
		return l.str == r.str;
	}
};
std::set<
std::hash_set<Bucke

 std::vector<Bucket*> mBuckets;


    ~StringHashTable()
    {
        delete[] m_table;
        for (uint i = 0; i < m_blocks.size(); i++)
        {
            delete[] m_blocks[i];
        }
    }

	static uint fnv1Hash(const char *key)
	{
		uint hash = 2166136261;
		for (const char *s = key; *s; s++)
	        hash = (16777619 * hash) ^ (*s);
		return hash;
	};

    uint &operator[](const char *key)
    {
        uint hash = fnv1Hash(key) & (m_tableSize - 1);
        Bucket *firstBucket = m_table + hash;
        Bucket *b = firstBucket;
		if (b->key)
		{
			do
			{
				if (strcmp(b->key, key) == 0)
					return b->value;	// Found existing bucket
				b = b->next;
			}
			while (b);
		}
        // Add it
        m_numKeys++;
        if (!firstBucket->key)
        {
            firstBucket->setKey(key);	// Use bucket in table
            return firstBucket->value;
        }
        // Allocate a new bucket
        if (m_blockPos >= m_blockSize)
        {
            Bucket *block = new Bucket[m_blockSize];
            m_blocks.push_back(block);
            m_blockPos = 0;
        }
        b = m_blocks.back() + m_blockPos;
        m_blockPos++;
        b->setKey(key);
        b->next = firstBucket->next;
        firstBucket->next = b;
        return b->value;
    }
};

class StringHashTableTester : public BaseTester
{
private:
	StringHashTable m_wordCount;

public:
	StringHashTableTester(uint tableSize) : m_wordCount(tableSize)
	{
	}

	void readWords(WordReader &reader)
	{
		while (const char *word = reader.getWord())
		{
			m_wordCount[word] += 1;
		}
	}

	void getWords(vector<pair<int, string> > &wordList)
	{
		typedef StringHashTable::Bucket Bucket;
		wordList.reserve(m_wordCount.m_numKeys);
		uint i;
		for (i = 0; i < m_wordCount.m_tableSize; i++)
		{
			Bucket *b = m_wordCount.m_table + i;
			if (b->key)
				wordList.push_back(pair<int, string>(b->value, b->key));
		}
		for (i = 0; i < m_wordCount.m_blocks.size(); i++)
		{
			Bucket *block = m_wordCount.m_blocks[i];
			for (uint j = 0; j < m_wordCount.m_blockSize; j++)
			{
				if (block[j].key)
					wordList.push_back(pair<int, string>(block[j].value, block[j].key));
			}
		}
	}
};

BaseTester *CreateStringHashTableTester(uint param)
{
	return new StringHashTableTester(param);
}

StringTable::StringTable(const char* str)
{

}
const char* StringTable::str() const
{

}
int StringTable::len() const
{

}

bool StringTable::operator==(const char* r)
{
			
}
bool StringTable::operator!=(const char* r)
{

}
bool StringTable::operator==(const std::string& r)
{
			
}
bool StringTable::operator!=(const std::string& r)
{

}
bool StringTable::operator==(const StringTable& r) { return r._h == _h; }
bool StringTable::operator!=(const StringTable& r) { return r._h != _h;}
// Good enough for lua, its good enough for us

static TString *newlstr (lua_State *L, const char *str, size_t l,
                                       unsigned int h) {
  size_t totalsize; // /* total size of TString object 
  GCObject **list; // /* (pointer to) list where it will be inserted 
  TString *ts;
  stringtable *tb = &G(L)->strt;
  if (l+1 > (MAX_SIZET - sizeof(TString))/sizeof(char))
    luaM_toobig(L);
  if (tb->nuse >= cast(lu_int32, tb->size) && tb->size <= MAX_INT/2)
    luaS_resize(L, tb->size*2);  ///* too crowded 
  totalsize = sizeof(TString) + ((l + 1) * sizeof(char));
  list = &tb->hash[lmod(h, tb->size)];
  ts = &luaC_newobj(L, LUA_TSTRING, totalsize, list, 0)->ts;
  ts->tsv.len = l;
  ts->tsv.hash = h;
  ts->tsv.reserved = 0;
  memcpy(ts+1, str, l*sizeof(char));
  ((char *)(ts+1))[l] = '\0';  //ending 0 
  tb->nuse++;
  return ts;
}


TString *luaS_newlstr (lua_State *L, const char *str, size_t l) {
  GCObject *o;
  unsigned int h = cast(unsigned int, l);  // seed 
  size_t step = (l>>5)+1; // if string is too long, don't hash all its chars 
  size_t l1;
  for (l1=l; l1>=step; l1-=step)  // compute hash 
    h = h ^ ((h<<5)+(h>>2)+cast(unsigned char, str[l1-1]));
  for (o = G(L)->strt.hash[lmod(h, G(L)->strt.size)];
       o != NULL;
       o = gch(o)->next) {
    TString *ts = rawgco2ts(o);
    if (h == ts->tsv.hash &&
        ts->tsv.len == l &&
        (memcmp(str, getstr(ts), l * sizeof(char)) == 0)) {
      if (isdead(G(L), o))  // string is dead (but was not collected yet)? 
        changewhite(o);  // resurrect it 
      return ts;
    }
  }
  return newlstr(L, str, l, h);  // not found; create a new string 
}


TString *luaS_new (lua_State *L, const char *str) {
  return luaS_newlstr(L, str, strlen(str));
}
*/