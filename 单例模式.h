/*单例模式（一）*/
//std::mutex mt;
//class Instance
//{
//public:
//	getInstance()
//	{
//		if (ptr == NULL)       //双重检查
//		{
//			mt.lock();
//			if (ptr == NULL)
//			{
//				ptr = new Instance;
//			}
//			mt.unlock();
//		}
//	}
//private:
//  Instance(){}
//	static Instance* ptr;
//	class destory
//	{
//	public:
//		~destory()
//		{
//			if (ptr != NULL)
//			{
//				delete ptr;
//			}
//		}
//	};
//	static destory ds;
//};
//Instance* Instance::ptr = NULL;
//Instance::destory Instance::ds;

/*单例模式（二）*/
//class Instance
//{
//public:
//	Instance* getInstance()
//	{
//		return ptr;
//	}
//private:
//	static Instance* ptr;
//};
//Instance* Instance::ptr = new Instance;

/*单例模式（三）*/
//class Instance
//{
//public:
//	Instance* getInstance()
//	{
//		static Instance _instance;
//		return &_instance;
//	}
//private:
//	Instance(){}
//};.h