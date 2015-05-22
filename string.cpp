bool operator==(CMyString a, CMyString b)
{
	for (int i = 0;; i++)
	{
		if ((a.pData[i] == '\0') && (b.pData[i] == '\0'))
			return 1;
		else
			if (a.pData[i] == '\0')
				return 0;
			else
				if (b.pData[i] == '\0')
					return 0;
				else
					if (a.pData[i] < b.pData[i])
						return 0;
					else
						if (a.pData[i] > b.pData[i])
							return 0;
	}
}
bool operator<(CMyString a, CMyString b)
{
	for (int i = 0;; i++)
	{
		if ((a.pData[i] == '\0') && (b.pData[i] == '\0'))
			return 0;
		else
			if (a.pData[i] == '\0')
				return 0;
			else
				if (b.pData[i] == '\0')
					return 1;
				else
					if (a.pData[i] < b.pData[i])
						return 0;
					else
						if (a.pData[i] > b.pData[i])
							return 1;
	}
}
bool operator>(CMyString a, CMyString b)
{
	for (int i = 0;; i++)
	{
		if ((a.pData[i] == '\0') && (b.pData[i] == '\0'))
			return 0;
		else
			if (a.pData[i] == '\0')
				return 1;
			else
				if (b.pData[i] == '\0')
					return 0;
				else
					if (a.pData[i] < b.pData[i])
						return 1;
					else
						if (a.pData[i] > b.pData[i])
							return 0;
	}
}
