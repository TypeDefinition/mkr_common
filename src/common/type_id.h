#pragma once

#include <atomic>
#include <cstdint>
#include <type_traits>

namespace mkr {
    typedef uint64_t type_id_t;

    /**
     * Utility class to generate a unique id for a group of classes.
     * Each child class of Base will have a type id generated starting from 0.
     * @tparam Base The base class of the category.
     */
    template<typename Base>
    class type_id {
    private:
        /// Current type id.
        static std::atomic<type_id_t> current_id_;

        /**
         * Generate the type id of a class. This exists so that get_id() can remove the cv of the template class.
         * @tparam Derived The derived class of Base. Derived may also be of type Base. This type is cv removed.
         * @return The type id of class Derived.
         */
        template<typename Derived>
        static type_id_t generate() {
            static type_id_t id = current_id_++;
            return id;
        }

    public:
        type_id() = delete;

        /**
         * Get the type id of a class.
         * @tparam Derived The class type. Derived may also be of type Base.
         * @return The type id of Derived.
         */
        template<typename Derived>
        static type_id_t value() requires std::is_base_of_v<Base, Derived> {
            return generate<std::remove_cvref_t<Derived>>();
        }
    };

    /// Type id starts from 0.
    template<typename Base>
    std::atomic<type_id_t> type_id<Base>::current_id_ = 0;
}