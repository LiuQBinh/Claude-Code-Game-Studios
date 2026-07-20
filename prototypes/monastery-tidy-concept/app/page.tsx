const prototypes = [
  {
    href: "/static/prototype-hub.html",
    title: "Hub + Mini-game",
    blurb: "Walk the cutaway, enter a room, tidy props, unlock books.",
  },
  {
    href: "/static/prototype.html",
    title: "Tidy Mini-game",
    blurb: "Drag-drop clutter onto home spots and fill the purity meter.",
  },
] as const;

export default function HomePage() {
  return (
    <main
      style={{
        minHeight: "100vh",
        display: "grid",
        placeItems: "center",
        padding: "32px 20px",
      }}
    >
      <div style={{ width: "min(520px, 100%)" }}>
        <p
          style={{
            fontSize: 12,
            letterSpacing: "0.08em",
            textTransform: "uppercase",
            opacity: 0.65,
            marginBottom: 10,
          }}
        >
          Concept prototype
        </p>
        <h1
          style={{
            fontSize: "clamp(1.8rem, 4vw, 2.4rem)",
            lineHeight: 1.15,
            marginBottom: 12,
          }}
        >
          Monastery Tidy
        </h1>
        <p style={{ opacity: 0.8, marginBottom: 28, lineHeight: 1.5 }}>
          Static HTML prototypes hosted by Next.js. Open a build below.
        </p>

        <ul style={{ listStyle: "none", display: "grid", gap: 12 }}>
          {prototypes.map((item) => (
            <li key={item.href}>
              <a
                href={item.href}
                style={{
                  display: "block",
                  padding: "16px 18px",
                  border: "2px solid var(--brown)",
                  borderRadius: 6,
                  background: "rgba(240, 230, 211, 0.85)",
                  transition: "box-shadow 0.15s, transform 0.15s",
                }}
              >
                <strong style={{ display: "block", marginBottom: 4 }}>
                  {item.title}
                </strong>
                <span style={{ fontSize: 14, opacity: 0.75 }}>{item.blurb}</span>
              </a>
            </li>
          ))}
        </ul>
      </div>
    </main>
  );
}
