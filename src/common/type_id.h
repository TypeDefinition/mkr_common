#pragma once

#include <atomic>
#include <cstdint>
#include <type_traits>

namespace mkr {
    typedef uint64_t type_id_t;

    /**
     * Utility class to generate a unique id for classes. Different classes are guaranteed to get different ids in each application run, but may be assigned different ids between runs.
     * @tparam Category Used to allow multiple instances of type_id to exists in a single application.
     * Example: type_id<foo> for foo-related classes, and type_id<bar> for bar-related classes. Then, type_id<foo>::value<baz>() might not equal type_id<bar>::value<baz>().
     */
    template <typename Category>
    class type_id {
    private:
        /// Current type id.
        static std::atomic<type_id_t> current_id_;

        /**
         * Generate the type id of a class. This exists so that get_id() can remove the cv of the template class.
         * Subsequent calls to generate of the same type will return the same value.
         * @tparam T The type to generate the id of. This type is cv removed.
         * @return The type id of class T.
         */
        template <typename T>
        static type_id_t generate() {
            static type_id_t id = current_id_++;
            return id;
        }

    public:
        type_id() = delete;

        /**
         * Get the type id of a class.
         * @tparam The class type.
         * @return The type id of T.
         */
        template <typename T>
        static type_id_t value() {
            return generate<std::remove_cvref_t<T>>();
        }
    };

    /// Type id starts from 0.
    template <typename Category>
    std::atomic<type_id_t> type_id<Category>::current_id_ = 0;

    #define MKR_TYPE_ID(Category, Type) type_id<Category>::value<T>()
} // mkr