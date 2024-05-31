#pragma once

#include <random>
#include <cstdint>
#include <bitset>

namespace mkr {
    class uuid {
    private:
        uint64_t id_;

        inline static std::random_device device;
        inline static std::mt19937_64 engine = std::mt19937_64(device());
        inline static std::uniform_int_distribution<uint64_t> distribution;

    public:
        uuid() : id_(distribution(engine)) {}
        uuid(const uuid &) = default;
        explicit uuid(uint64_t _id) : id_(_id) {}

        uuid& operator=(const uuid& _rhs) = default;
        bool operator==(const uuid& _rhs) const { return id_ == _rhs.id_; }
        bool operator!=(const uuid& _rhs) const { return id_ != _rhs.id_; }
        bool operator<(const uuid& _rhs) const { return id_ < _rhs.id_; }
        bool operator>(const uuid& _rhs) const { return id_ > _rhs.id_; }
        bool operator<=(const uuid& _rhs) const { return id_ <= _rhs.id_; }
        bool operator>=(const uuid& _rhs) const { return id_ >= _rhs.id_; }

        explicit operator uint64_t() const { return id_; }
    };

}

namespace std {
    template<>
    struct hash<::mkr::uuid> {
        std::size_t operator()(const ::mkr::uuid &_uuid) const {
            return std::hash<uint64_t>{}((uint64_t) _uuid);
        }
    };
}