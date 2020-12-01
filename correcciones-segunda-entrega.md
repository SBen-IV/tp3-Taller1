# Correcciones

Corregido todo lo propuesto.
A tener en cuenta:

Tratar de mover la lógica que es única del servidor al servidor y no en common
Faltó eliminar Socket::operator=(Socket&&) (si se usa el default hay leak de recursos)

Nota: 10
