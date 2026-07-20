import type { Metadata } from "next";
import "./globals.css";

export const metadata: Metadata = {
  title: "Monastery Tidy — Concept Prototypes",
  description:
    "HTML concept prototypes for Monastery Tidy: hub + tidy mini-game.",
};

export default function RootLayout({
  children,
}: Readonly<{
  children: React.ReactNode;
}>) {
  return (
    <html lang="en">
      <body>{children}</body>
    </html>
  );
}
