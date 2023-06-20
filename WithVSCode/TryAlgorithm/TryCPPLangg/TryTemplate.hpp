#ifndef TRY_TEMPLATE_H
#define TRY_TEMPLATE_H

namespace TryCPPLangg{
    namespace TryTemplate{
        template <typename T>
        T Add(const T& a, const T& b);

        void TestForTemplateAdd();
        
        void ContextForUniquePtr();
        
        void TestForUniquePtr();
        void MainForTemplate(); 
    }
}

#endif