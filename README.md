# Advent of Code 2024 csboo

## Meson usage

- setup

```meson setup builddir```

- build all days

```ninja -C builddir all```

- build specific day

```ninja -C builddir [number_of_day] / "day" + [number_of_day]```

- run a built day (or build and run)

```ninja -C builddir [number_of_day]```
