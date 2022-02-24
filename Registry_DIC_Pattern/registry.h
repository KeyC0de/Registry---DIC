#include <memory>
#include <unordered_map>
#include <string>
#include "condnoex.h"


class IClass;

// Registry DIC class
class Dic final
{
	std::unordered_map<std::string, std::shared_ptr<IClass>> m_umap;
public:
	template<class T, typename... TArgs>
	static std::shared_ptr<T> fetch( TArgs&&... args ) cond_noex
	{
		static_assert( std::is_base_of<IClass, T>::value, "T must be a IClass!" );
		return getInstance().fetch_impl<T>( std::forward<TArgs>( args )... );
	}
private:
	template<class T, typename... TArgs>
	std::shared_ptr<T> fetch_impl( TArgs&&... args ) cond_noex
	{
		const auto classId = T::generateUid( std::forward<TArgs>( args )... );
		const auto elem = m_umap.find( classId );
		if ( elem == m_umap.end() )
		{
			auto obj = std::make_shared<T>( std::forward<TArgs>( args )... );
			m_umap[classId] = obj;
			return obj;
		}
		else
		{
			return std::static_pointer_cast<T>( elem->second );
		}
	}

	static Dic& getInstance()
	{
		static Dic instance;
		return instance;
	}
};